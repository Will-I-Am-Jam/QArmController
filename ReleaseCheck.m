function newState  = ReleaseCheck(p4, v4, p_goal, v_goal, r_p_in, r_p_out, r_v_in, gripperMode)
%#codegen
% Determines the state of the gripper on the QArm based on the end-effector
% position and velocity output by qarmForwardKinematics. The object is
% released when the end effector reaches the goal position AND the goal
% velocity. Uses hysteresis to prevent chattering.
% Inputs:
%   p4          - 3x1 end-effector position in frame {0} (m)
%   v4          - 3x1 end-effector linear velocity in frame {0} (m/s)
%   p_goal      - 3x1 goal end-effector position in frame {0} (m)
%   v_goal      - 3x1 goal end-effector velocity in frame {0} (m/s)
%   r_p_in      - inner position tolerance (per axis, m); every axis must be
%                 inside this to release the gripper (1 -> 0)
%   r_p_out     - outer position tolerance (per axis, m); any axis leaving
%                 this closes the gripper again (0 -> 1)
%                 (r_p_out > r_p_in creates the hysteresis band)
%   r_v_in      - velocity tolerance (per axis, m/s); every axis of the
%                 velocity error must be inside this to release
%   gripperMode - current gripper state (0 or 1) 0 is open and 1 is closed
% Output:
%   newState    - updated gripper state (0 or 1)



    checkVel = [1;1;1];
%               - velocity check enable flag(s). Scalar: 1 checks velocity
%                 on all axes, 0 ignores velocity. 3x1: enables the check
%                 per axis, e.g. [1;0;0] only checks the x velocity

    % calculate Cartesian position and velocity error
    p_err = p_goal(:) - p4(:);
    v_err = v_goal(:) - v4(:);

    if (gripperMode > 0.5)
        gripperMode = 1;
    else
        gripperMode = 0;
    end
    % default: hold the current state
    newState = gripperMode;

    if gripperMode == 1
        % release only when EVERY axis is inside the inner band and the
        % end effector is moving at (nearly) the goal velocity. Axes with
        % the velocity check disabled always pass.
        velOk = (abs(v_err) <= r_v_in(:)) | ~logical(checkVel(:));
        inside = all(abs(p_err) <= r_p_in(:)) && all(velOk);
        if inside
            newState = 0;
        end

    else
        % close again when ANY axis leaves the outer band
        outside = any(abs(p_err) >= r_p_out(:));
        if outside
            newState = 1;
        end
    end

end
