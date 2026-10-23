function tests = ReleaseCheckTest
%#codegen

% Unit tests for ReleaseCheck. Run with:  results = runtests('ReleaseCheckTest')
%
% Velocity is checked against the SAME r_in / r_out as position:
%   0 -> 1 when ALL |p_err| <= r_in  AND ALL |v_err| <= r_in
%   1 -> 0 when ANY |p_err| >  r_out AND ANY |v_err| >  r_out
    tests = functiontests(localfunctions);
end

function setupOnce(testCase)
    % shared fixture: 3-axis goal, inner band 0.01, outer band 0.05
    testCase.TestData.p_goal = [0.5; 0.2; 0.3];
    testCase.TestData.v_goal = [0; 0; 0];
    testCase.TestData.r_in   = [0.01; 0.01; 0.01];
    testCase.TestData.r_out  = [0.05; 0.05; 0.05];
end

% helper: p and v given as offsets from the goal
function s = call(testCase, dp, dv, mode)
    d = testCase.TestData;
    s = ReleaseCheck(d.p_goal + dp, d.v_goal + dv, d.p_goal, d.v_goal, ...
                     d.r_in, d.r_out, mode);
end

%% Mode 0 -> 1: position (velocity at goal)

function testMode0_AtGoal_SwitchesTo1(testCase)
    verifyEqual(testCase, call(testCase, [0;0;0], [0;0;0], 0), 1);
end

function testMode0_PosInsideInnerBand_SwitchesTo1(testCase)
    verifyEqual(testCase, call(testCase, [0.005; -0.005; 0.009], [0;0;0], 0), 1);
end

function testMode0_PosExactlyOnInnerBoundary_SwitchesTo1(testCase)
    % goal at origin so |p_err| == r_in exactly (no float round-off)
    d = testCase.TestData;
    s = ReleaseCheck(-d.r_in, [0;0;0], [0;0;0], [0;0;0], d.r_in, d.r_out, 0);
    verifyEqual(testCase, s, 1);
end

function testMode0_PosOneAxisOutsideInnerBand_StaysAt0(testCase)
    verifyEqual(testCase, call(testCase, [0; 0; 0.011], [0;0;0], 0), 0);
end

function testMode0_PosInHysteresisBand_StaysAt0(testCase)
    verifyEqual(testCase, call(testCase, [0.03; 0.03; 0.03], [0;0;0], 0), 0);
end

%% Mode 0 -> 1: velocity (position at goal)

function testMode0_VelInsideInnerBand_SwitchesTo1(testCase)
    verifyEqual(testCase, call(testCase, [0;0;0], [0.005; -0.009; 0], 0), 1);
end

function testMode0_VelExactlyOnInnerBoundary_SwitchesTo1(testCase)
    d = testCase.TestData;
    s = ReleaseCheck([0;0;0], d.r_in, [0;0;0], [0;0;0], d.r_in, d.r_out, 0);
    verifyEqual(testCase, s, 1);
end

function testMode0_VelOneAxisOutsideInnerBand_StaysAt0(testCase)
    % at the right spot but still moving -> don't switch
    verifyEqual(testCase, call(testCase, [0;0;0], [0; -0.011; 0], 0), 0);
end

function testMode0_PosAndVelBothOutside_StaysAt0(testCase)
    verifyEqual(testCase, call(testCase, [0.1;0;0], [0.1;0;0], 0), 0);
end

function testMode0_NonzeroVelGoal(testCase)
    % v_err is measured relative to v_goal, not to zero
    d = testCase.TestData;
    v_goal = [0.2; 0; 0];
    s = ReleaseCheck(d.p_goal, [0.205; 0; 0], d.p_goal, v_goal, d.r_in, d.r_out, 0);
    verifyEqual(testCase, s, 1);
    s = ReleaseCheck(d.p_goal, [0; 0; 0], d.p_goal, v_goal, d.r_in, d.r_out, 0);
    verifyEqual(testCase, s, 0);
end

%% Mode 1 -> 0: needs BOTH position and velocity outside r_out

function testMode1_AtGoal_StaysAt1(testCase)
    verifyEqual(testCase, call(testCase, [0;0;0], [0;0;0], 1), 1);
end

function testMode1_BothInHysteresisBand_StaysAt1(testCase)
    verifyEqual(testCase, call(testCase, [0.03;-0.03;0.04], [0.03;0;0], 1), 1);
end

function testMode1_BothExactlyOnOuterBoundary_SwitchesTo0(testCase)
    d = testCase.TestData;
    s = ReleaseCheck(d.r_out, d.r_out, [0;0;0], [0;0;0], d.r_in, d.r_out, 1);
    verifyEqual(testCase, s, 0);
end

function testMode1_PosAndVelOutside_SwitchesTo0(testCase)
    verifyEqual(testCase, call(testCase, [0; -0.051; 0], [0; 0; 0.06], 1), 0);
end

function testMode1_PosAndVelOutsideOnDifferentAxes_SwitchesTo0(testCase)
    % "any" is evaluated separately for p and v, so axes needn't match
    verifyEqual(testCase, call(testCase, [0.1; 0; 0], [0; 0; 0.1], 1), 0);
end

function testMode1_OnlyPosOutside_StaysAt1(testCase)
    verifyEqual(testCase, call(testCase, [1; 1; 1], [0;0;0], 1), 0);
end

function testMode1_OnlyVelOutside_StaysAt1(testCase)
    verifyEqual(testCase, call(testCase, [0;0;0], [1; 1; 1], 1), 0);
end

%% Hysteresis / chattering

function testNoChatteringAcrossInnerBoundary(testCase)
    % position jitters across r_in; once switched to 1 it must hold
    offsets = [0.02, 0.009, 0.011, 0.009, 0.012, 0.008, 0.02];
    state = 0;
    history = zeros(size(offsets));
    for k = 1:numel(offsets)
        state = call(testCase, [offsets(k); 0; 0], [0;0;0], state);
        history(k) = state;
    end
    verifyEqual(testCase, history, [0 1 1 1 1 1 1]);
end

function testFullCycle(testCase)
    % approach -> settle -> drift -> move away fast
    dps = [0.1, 0.04, 0.005, 0.005, 0.04, 0.06,  0.1];
    dvs = [0.1, 0.02, 0.02,  0.0,   0.02, 0.02,  0.08];
    exp = [0,   0,    0,     1,     1,    0,     0];
    %                 ^ in position but still moving
    %                                     ^ pos out, vel in -> hold
    state = 0;
    for k = 1:numel(dps)
        state = call(testCase, [0; dps(k); 0], [0; dvs(k); 0], state);
        verifyEqual(testCase, state, exp(k), sprintf('step %d', k));
    end
end

%% Misc

function testPerAxisTolerances(testCase)
    d = testCase.TestData;
    r_in = [0.1; 0.01; 0.01];
    s = ReleaseCheck(d.p_goal + [0.08;0;0], [0.08;0;0], d.p_goal, d.v_goal, ...
                     r_in, d.r_out, 0);
    verifyEqual(testCase, s, 1);
end

function testRowVectorInputs(testCase)
    d = testCase.TestData;
    s = ReleaseCheck(d.p_goal', d.v_goal', d.p_goal', d.v_goal', d.r_in', d.r_out', 0);
    verifyEqual(testCase, s, 1);
end

function testUnknownMode_ReturnsSameMode(testCase)
    f = @() call(testCase, [0;0;0], [0;0;0], 7);
    [~, s] = evalc('f()');  % suppress the fprintf
    verifyEqual(testCase, s, 7);
end
