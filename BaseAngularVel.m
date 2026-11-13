function [phi_cmd] = BaseAngularVel(w_des, phi, Ts, enable, reverse)
%#codegen
% Spins the QArm base (joint 1) at a desired angular velocity in position
% mode. Every sample the base angle command is moved forward by w_des*Ts,
% so the position controller drags the base along at w_des. The other
% joints are held at the pose they were in when the model started.
%
% Inputs:
%   w_des   - desired base angular velocity (rad/s), positive = counter-clockwise
%   phi     - 4x1 joint angles from the Hardware Plant (rad)
%   Ts      - sample time of the block (s), e.g. a Constant set to qc_get_step_size
%   enable  - 1 moves the arm, 0 pauses it where it is; moving picks up
%             from the same spot when enable returns to 1
% Output:
%   phi_cmd - 4x1 joint angle command for the Hardware Plant (rad)

    phi2_min = -70 * pi/180;   % base limits (rad), same as SpeedControlUsingPosition
    phi2_max =  70 * pi/180;

    enable = 1;
    persistent cmd
    if (isempty(cmd) && enable > 0.5)
        cmd = [0;-1.1318;-pi/2;0];   % start from the current pose so the arm doesn't jump
    end

    if (not(isempty(cmd)))
        % paused: keep sending the same command so the arm holds still
        if enable < 0.5
            phi_cmd = cmd;
            return
        end

        % move the base command forward by one sample's worth of rotation,
        % and stop at the limits
        if (reverse)
            cmd(2) = cmd(2) - w_des * Ts;
        else
            cmd(2) = cmd(2) + w_des * Ts;
        end
        cmd(2) = min(max(cmd(2), phi2_min), phi2_max);
        cmd(3) = -1.63712;
        phi_cmd = cmd;
    else 
        phi_cmd = phi(:);
    end
end
