P_start = [0.1083 0 0.4618];
P_end = [0.6828 0 0.3521];
T_goal = 5;
f_cmd = 20;
[phi_cmds, valid] = P2PVelocityController(P_start, P_end, T_goal, f_cmd);

% disp(phi_cmds);
if all(valid)
    disp('All positions valid');
else
    bad = find(~valid);
    fprintf('%d invalid steps, first at step %d (t = %.2f s)\n', ...
        numel(bad), bad(1), (bad(1)-1)/f_cmd);
end

dphi = diff(phi_cmds, 1, 2);                % change per step, 4 x (numSteps-1)
w = max(abs(dphi), [], 2) * f_cmd;          % peak joint speed (rad/s) per joint
w_max = 1.0;                                % pick your limit (rad/s)
fprintf('Peak joint speeds (rad/s): %s\n', mat2str(w', 3));
if any(w > w_max)
    warning('Joint speed exceeds %.2f rad/s', w_max);
end