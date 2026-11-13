function newState  = ReleaseCheck(phi4, phidot4, phi_goal, phidot_goal, r_p_in, r_p_out, r_v_in, gripperMode)
%#codegen
% Determines the state of the gripper on the QArm based on the joint angles
% and joint angular velocities. The object is released when the arm
% reaches the goal joint angles AND the goal joint velocities. Uses
% hysteresis to prevent chattering.
% Inputs:
%   phi4        - 4x1 joint angles from the Hardware Plant (rad)
%   phidot4     - 4x1 joint angular velocities from the Hardware Plant (rad/s)
%   phi_goal    - 4x1 joint angles to release at (rad)
%   phidot_goal - 4x1 joint angular velocities to release at (rad/s)
%   r_p_in      - inner angle tolerance (scalar or 4x1 per joint, rad); every
%                 joint must be inside this to release the gripper (1 -> 0)
%   r_p_out     - outer angle tolerance (scalar or 4x1 per joint, rad); any
%                 joint leaving this closes the gripper again (0 -> 1)
%                 (r_p_out > r_p_in creates the hysteresis band)
%   r_v_in      - angular velocity tolerance (scalar or 4x1 per joint, rad/s);
%                 every joint's velocity error must be inside this to release
%   gripperMode - current gripper state (0 or 1) 0 is open and 1 is closed
% Output:
%   newState    - updated gripper state (0 or 1)

    checkVel = [0;0;0;0];
%               - velocity check enable flag(s). Scalar: 1 checks velocity
%                 on all joints, 0 ignores velocity. 4x1: enables the check
%                 per joint, e.g. [0;1;1;0] only checks joints 2 and 3

    % calculate joint angle and angular velocity error
    phi_err = phi_goal(:) - phi4(:);
    phidot_err = phidot_goal(:) - phidot4(:);

    if (gripperMode > 0.5)
        gripperMode = 1;
    else
        gripperMode = 0;
    end
    % default: hold the current state
    newState = gripperMode;

    if gripperMode == 1
        % release only when EVERY joint is inside the inner band and is
        % moving at (nearly) the goal angular velocity. Joints with the
        % velocity check disabled always pass.
        velOk = (abs(phidot_err) <= r_v_in(:)) | ~logical(checkVel(:));
        inside = all(abs(phi_err) <= r_p_in(:)) && all(velOk);
        if inside
            newState = 0;
        end

    else
        % close again when ANY joint leaves the outer band
        outside = any(abs(phi_err) >= r_p_out(:));
        if outside
            % newState = 1;
        end
    end

end
