function [pwm_cmd, phi3_ref, fault] = ElbowSpeedControl(omega_des, phi, phi_dot, enable, Ts)
%#codegen
% Drives the QArm elbow (joint 3, phi(3)) at a desired speed using PWM mode.
% The elbow must be set to PWM mode in HIL Initialize (j2_mode=1).
%
% Control law (velocity tracking with a moving position reference):
%   phi3_ref integrates omega_des, so the elbow follows a ramp at the
%   desired speed. Holding omega_des = 0 makes the elbow hold its position.
%     u = Kff*omega_des + Kv*(omega_des - w) + Kp*(phi3_ref - phi3) + gravity
%
% Inputs:
%   omega_des - desired elbow speed (rad/s)
%   phi       - 4x1 joint angles from the Hardware Plant (rad)
%   phi_dot   - 4x1 joint velocities from the Hardware Plant (rad/s)
%   enable    - 1 runs the controller, 0 outputs zero PWM (elbow goes limp!)
%   Ts        - controller sample time (s)
% Outputs:
%   pwm_cmd   - 4x1 PWM command for the Hardware Plant "PWM Cmd" port,
%               -1.0 to 1.0 (only element 3 is non-zero)
%   phi3_ref  - elbow position reference (rad), useful for plotting
%   fault     - 1 if the overspeed trip fired (toggle enable to clear)

    % ---- tuning parameters (starting guesses, tune on the real arm) ----
    Kff       = 0.15;   % PWM per rad/s of desired speed (feedforward)
    Kv        = 0.05;   % PWM per rad/s of speed error
    Kp        = 0.50;   % PWM per rad of position error
    Kg        = 0.00;   % gravity compensation PWM (sign depends on the arm)
    pwm_max   = 0.30;   % PWM saturation (0.30 = 30%)
    err_max   = 0.20;   % max reference lead over the actual angle (rad)
    phi3_min  = -1.60;  % soft limits, inside hardware range -1.74 .. +1.39
    phi3_max  =  1.25;
    w_trip    = 3.00;   % overspeed trip (rad/s)

    persistent ref prev_enable tripped
    if isempty(ref)
        ref = phi(3);
        prev_enable = 0;
        tripped = 0;
    end

    pwm_cmd = zeros(4, 1);
    phi3 = phi(3);
    w = phi_dot(3);

    % disabled: zero output, reset reference and fault
    if enable < 0.5
        ref = phi3;
        tripped = 0;
        prev_enable = 0;
        phi3_ref = ref;
        fault = tripped;
        return;
    end

    % rising edge of enable: start the reference at the current angle
    if prev_enable < 0.5
        ref = phi3;
    end
    prev_enable = 1;

    % overspeed trip latches until enable is toggled
    if abs(w) > w_trip
        tripped = 1;
    end
    if tripped
        phi3_ref = ref;
        fault = tripped;
        return;
    end

    % advance the reference, keep it inside the soft limits and close
    % enough to the actual angle to avoid wind-up when PWM saturates
    ref = ref + omega_des*Ts;
    ref = min(max(ref, phi3 - err_max), phi3 + err_max); % FIX
    ref = min(max(ref, phi3_min), phi3_max);

    % stop feeding forward speed once the reference is parked at a limit
    w_ff = omega_des;
    if (ref >= phi3_max && omega_des > 0) || (ref <= phi3_min && omega_des < 0)
        w_ff = 0;
    end

    % gravity torque on the elbow ~ cos(forearm angle from horizontal);
    % the forearm is horizontal when phi(2) + phi(3) = 0
    u_g = Kg*cos(phi(2) + phi3); % FIX: need to figure out what this is

    u = Kff*w_ff + Kv*(w_ff - w) + Kp*(ref - phi3) + u_g;
    pwm_cmd(3) = min(max(u, -pwm_max), pwm_max);

    pwm_cmd(3) = -1 .* pwm_cmd(3);
    phi3_ref = ref;
    fault = tripped;
end
