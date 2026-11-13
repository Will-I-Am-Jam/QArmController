% Generates a trajectory that makes the end effector follow a curve, by
% splitting the curve into many short straight legs with waypointTraj.
% The result (phi_cmds) is ready to run on the QArm with runTraj.
addpath(fullfile(fileparts(mfilename('fullpath')), '..'));   % qarmForwardKinematics etc.

f_cmd = 20;      % command rate (Hz)
v_tip = 0.05;    % end-effector speed along the curve (m/s)
numPts = 41;     % waypoints along the curve, more = closer to the true curve

% curve to follow: a circle in a horizontal plane, s goes 0 -> 1 along it
center = [0.40; 0; 0.35];   % (m)
radius = 0.08;              % (m)
curve = @(s) center + radius * [cos(2*pi*s); sin(2*pi*s); zeros(size(s))];
% other examples:
%   arc in the vertical x-z plane:  curve = @(s) center + radius * [cos(pi*s); zeros(size(s)); sin(pi*s)];
%   figure eight:                   curve = @(s) center + radius * [zeros(size(s)); sin(2*pi*s); sin(4*pi*s)/2];

P_goals = curve(linspace(0, 1, numPts));   % 3 x numPts waypoints

% time for each leg from its length, so the tip moves at a constant speed;
% rounded to a whole number of steps so every leg ends exactly on its waypoint
leg_len = vecnorm(diff(P_goals, 1, 2));
T_goals = max(round(leg_len / v_tip * f_cmd), 1) / f_cmd;

[phi_cmds, valid] = waypointTraj(P_goals, T_goals, f_cmd);
approved = trajValidator(phi_cmds, valid, f_cmd);

% check how closely the commanded tip path follows the true curve
numCmds = size(phi_cmds, 2);
P_cmds = zeros(3, numCmds);
for i = 1:numCmds
    P_cmds(:, i) = qarmForwardKinematics(phi_cmds(:, i));
end
P_true = curve(linspace(0, 1, 2000));
dev = zeros(1, numCmds);
for i = 1:numCmds
    dev(i) = min(vecnorm(P_true - P_cmds(:, i)));
end
fprintf('Duration: %.2f s, %d commands\n', (numCmds-1)/f_cmd, numCmds);
fprintf('Max distance from the curve: %.2f mm\n', max(dev)*1000);

% plot the tip path in 3D and the joint angles over time
figure;
subplot(1, 2, 1);
plot3(P_true(1,:), P_true(2,:), P_true(3,:), 'k--');
hold on;
plot3(P_cmds(1,:), P_cmds(2,:), P_cmds(3,:), 'b.-');
plot3(P_goals(1,:), P_goals(2,:), P_goals(3,:), 'ro');
hold off;
axis equal;
grid on;
xlabel('x (m)'); ylabel('y (m)'); zlabel('z (m)');
legend('curve', 'commanded tip path', 'waypoints', 'Location', 'southoutside');
title('End-effector path');

subplot(1, 2, 2);
t = (0:numCmds-1) / f_cmd;
plot(t, phi_cmds' * 180/pi);
xlabel('Time (s)');
ylabel('Joint angle (deg)');
legend('\phi_1', '\phi_2', '\phi_3', '\phi_4');
title('Joint angles');
grid on;

if approved
    disp('Trajectory approved, phi_cmds is ready for runTraj');
    fprintf('Move the arm to the start pose first: %s rads\n', mat2str(round(phi_cmds(:,1), 4)));
else
    disp('Trajectory NOT approved, fix it before running on the arm');
end
phi_cmds = round(phi_cmds, 6);
disp(mat2str(phi_cmds));
