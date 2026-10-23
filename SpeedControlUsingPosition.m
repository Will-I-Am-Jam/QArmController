% function [phi_cmd] = SpeedControlUsingPosition(w_des, phi, Ts)
%     %#codegen
%     %Warning this will not hold all the joints in place
%     %w_des - 4x1 desired angluar vecloicity

%     phi_min = [-70; -70; -70; -70] * pi/180;
%     phi_max = [70; 70; 70; 70] * pi/180;

%     phi_cmd = phi + w_des(:) * Ts;
%     for i = 1:length(phi_cmd)
%         phi_cmd(i) = max(phi_min(i),min(phi_cmd(i),phi_max(i)));
%     end
% end



%uses the starting position of the joints as a reference to compensate for moving 2 fast or slow

function [phi_cmd] = SpeedControlUsingPosition(w_des, phi, Ts, f_cmd)
%#codegen
    phi_min = [-70; -70; -70; -70] * pi/180;
    phi_max = [ 70;  70;  70;  70] * pi/180;
    err_max = 0.2;   % max lead of the reference over the actual angle (rad)
    % f_cmd   = 30;    % how often phi_cmd is updated (Hz), must be <= 1/Ts

    persistent ref
    persistent count
    persistent cmd
    if isempty(ref)
        ref = phi(:);          % lock in the starting pose once
        cmd = ref;             % hold the starting pose until the first update
        count = 0;
    end

    ref = ref + w_des(:) * Ts;                                % only moving joints change
    % ref = min(max(ref, phi(:) - err_max), phi(:) + err_max);  % anti-windup
    ref = min(max(ref, phi_min), phi_max);                    % joint limits

    % only send a new command every 1/f_cmd seconds, hold it in between
    n_steps = max(1, round(1/(f_cmd*Ts)));
    count = count + 1;
    if count >= n_steps
        cmd = ref;
        count = 0;
    end

    phi_cmd = cmd;
end
