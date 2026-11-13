function [approved] = trajValidator(phi_cmds, valid, f_cmd)
    approved = true;
    % disp(mat2str(phi_cmds));
    if all(valid)
        disp('All positions valid');
    else
        bad = find(~valid);
        fprintf('%d invalid steps, first at step %d (t = %.2f s)\n', ...
            numel(bad), bad(1), (bad(1)-1)/f_cmd);
        approved = false;
    end

    dphi = diff(phi_cmds, 1, 2);                % change per step, 4 x (numSteps-1)
    w = max(abs(dphi), [], 2) * f_cmd;          % peak joint speed (rad/s) per joint
    w_max = 3.0;                                % pick your limit (rad/s)
    fprintf('Peak joint speeds (rad/s): %s\n', mat2str(w', 3));
    if any(w > w_max)
        warning('Joint speed exceeds %.2f rad/s', w_max);
        approved = false;
    end

    % end effector must stay above the base (z = 0 in frame {0}) plus a margin
    z_min = 0.05;                               % margin above the base (m)
    z = zeros(1, size(phi_cmds, 2));
    for i = 1:size(phi_cmds, 2)
        p4 = qarmForwardKinematics(phi_cmds(:, i));
        z(i) = p4(3);
    end
    fprintf('Lowest end-effector height: %.3f m\n', min(z));
    if any(z < z_min)
        low = find(z < z_min);
        warning('End effector goes below %.3f m (%d steps, first at step %d, t = %.2f s)', ...
            z_min, numel(low), low(1), (low(1)-1)/f_cmd);
        approved = false;
    end

end