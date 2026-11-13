% Generates a straight-line trajectory through a list of waypoints and
% checks it before running it on the QArm with runTraj.
addpath(fullfile(fileparts(mfilename('fullpath')), '..'));   % qarmForwardKinematics etc.

% waypoints as joint angles, one column per waypoint
phi_goals = [  0,      0,     0,      0,   0,   0,   0,   0,   0,     0,   0,     0,   0,     0,  0,   0,  0;
             -69, -64.25, -59.5, -54.75, -50, -45, -40, -35, -30, -27.5, -25, -22.5, -20, -12.5, -5, 2.5, 10;
             -30,    -30,   -30,    -30, -30, -30, -30, -30, -30,   -30, -30,   -30, -30,   -30, -30, -30, -30;
               0,      0,     0,      0,   0,   0,   0,   0,   0,     0,   0,     0,   0,     0,  0,   0,  0] * pi/180;
T_goals = 0.2 * ones(1, size(phi_goals, 2) - 1);   % time for each leg (s), one less than the number of waypoints

numGoals = size(phi_goals, 2);
pos_goals = zeros(3, numGoals);
for i = 1:numGoals
    pos_goals(:, i) = qarmForwardKinematics(phi_goals(:, i), [0;0;0;0]);
end

f_cmd = 20;

[phi_cmds, valid] = waypointTraj(pos_goals, T_goals, f_cmd);
approved = trajValidator(phi_cmds, valid, f_cmd);

% check the trajectory passes through each waypoint
wp_idx = 1 + [0, cumsum(round(T_goals * f_cmd))];   % column of each waypoint
wp_err = zeros(1, numGoals);
for i = 1:numGoals
    wp_err(i) = norm(qarmForwardKinematics(phi_cmds(:, wp_idx(i))) - pos_goals(:, i));
end
fprintf('Max waypoint position error: %.2e m\n', max(wp_err));

% plot the joint angles over time
t = (0:size(phi_cmds, 2)-1) / f_cmd;
figure;
plot(t, phi_cmds' * 180/pi);
hold on;
plot(t(wp_idx), phi_cmds(:, wp_idx)' * 180/pi, 'ko');
hold off;
xlabel('Time (s)');
ylabel('Joint angle (deg)');
legend('\phi_1', '\phi_2', '\phi_3', '\phi_4', 'waypoints');
title('Waypoint trajectory');
grid on;

if approved
    disp('Trajectory approved, phi_cmds is ready for runTraj');
else
    disp('Trajectory NOT approved, fix it before running on the arm');
end

phi_cmds = round(phi_cmds, 4);
disp(mat2str(phi_cmds));
