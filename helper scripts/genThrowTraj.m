% Generates a throwing trajectory for the QArm. The end effector winds up
% behind the arm, swings forward over the top on a circular arc, passes
% the release point, then slows to a stop on the follow-through.
% The tip starts at rest, speeds up smoothly to v_release at the release
% point, then slows smoothly back to rest. The result (phi_cmds) is ready
% to run on the QArm with runTraj.
addpath(fullfile(fileparts(mfilename('fullpath')), '..'));   % qarmForwardKinematics etc.

f_cmd = 20;          % command rate (Hz), must match f_cmd in the Simulink model
throw_dir = 0;       % direction to throw, as a base angle (deg), within +-70

% arc in the vertical plane of the throw, coordinates [forward, up] (m)

center = [0, 0.14];   % arc center (m)
radius = 0.70;              % (m)
th_start = 120;          % wind-up angle (deg)
th_end = 30;             % end of the follow-through (deg)
release_elev = 0;      % release when the tip velocity points this far above horizontal (deg),
                         % negative = past the top, heading down
v_angluar = 0.5;        % anuglar speed at release (rad/s), ~0.45 keeps joints under 1 rad/s
v_release = v_angluar * radius;
% moving forward over the arc, the velocity points release_elev above
% horizontal at angle 90 + release_elev
th_rel = 90 + release_elev;
if th_rel >= th_start || th_rel <= th_end
    error('release angle %.0f deg must be between th_end and th_start', th_rel);
end

% arc lengths before and after release (m)
L_acc = radius * (th_start - th_rel) * pi/180;
L_dec = radius * (th_rel - th_end) * pi/180;

% smooth speed profile: v = v_rel*(1-cos)/2 up to release, v_rel*(1+cos)/2 after.
% Each phase covers v_rel*T/2 of arc, which sets its duration. Rounded to a
% whole number of steps so the release lands exactly on a command.
N_acc = max(round(2*L_acc / v_release * f_cmd), 1);
N_dec = max(round(2*L_dec / v_release * f_cmd), 1);
T_acc = N_acc / f_cmd;
T_dec = N_dec / f_cmd;

t = (0:(N_acc + N_dec)) / f_cmd;
arc = zeros(size(t));   % distance travelled along the arc (m)
for k = 1:numel(t)
    if t(k) <= T_acc
        arc(k) = L_acc * (t(k)/T_acc - sin(pi*t(k)/T_acc)/pi);
    else
        td = t(k) - T_acc;
        arc(k) = L_acc + L_dec * (td/T_dec + sin(pi*td/T_dec)/pi);
    end
end
th = th_start*pi/180 - arc / radius;   % angle on the arc at each command (rad)

% arc points in the throw plane, then rotated to the throw direction
fwd = center(1) + radius*cos(th);
up = center(2) + radius*sin(th);
psi = throw_dir * pi/180;
P_goals = [fwd*cos(psi); fwd*sin(psi); up];

% one leg per command, so the speed profile is followed exactly
T_goals = ones(1, numel(t) - 1) / f_cmd;

[phi_cmds, valid] = waypointTraj(P_goals, T_goals, f_cmd);
approved = trajValidator(phi_cmds, valid, f_cmd);

% release point and velocity, e.g. for ReleaseCheck's p_goal and v_goal
release_idx = N_acc + 1;
t_release = T_acc;
p_release = P_goals(:, release_idx);
dir_plane = [sin(th(release_idx)), -cos(th(release_idx))];   % unit tangent [forward, up]
v_release_vec = v_release * [dir_plane(1)*cos(psi); dir_plane(1)*sin(psi); dir_plane(2)];

fprintf('Duration: %.2f s, %d commands\n', t(end), numel(t));
fprintf('Release at step %d (t = %.2f s)\n', release_idx, t_release);
fprintf('  p_release = %s m\n', mat2str(round(p_release', 3)));
fprintf('  v_release = %s m/s\n', mat2str(round(v_release_vec', 3)));

% release joint angles and angular velocities, for ReleaseCheck's phi_goal and phidot_goal
phi_release = phi_cmds(:, release_idx);
phidot_release = (phi_cmds(:, release_idx+1) - phi_cmds(:, release_idx-1)) * f_cmd/2;
fprintf('  phi_release    = %s rad\n', mat2str(round(phi_release', 4)));
fprintf('  phidot_release = %s rad/s\n', mat2str(round(phidot_release', 4)));

%% plot the throw in its vertical plane
figure;
subplot(1, 2, 1);
plot(fwd, up, 'b.-');
hold on;
plot(fwd(release_idx), up(release_idx), 'ro', 'MarkerFaceColor', 'r');
quiver(fwd(release_idx), up(release_idx), dir_plane(1)*0.15, dir_plane(2)*0.15, 0, 'r');
plot([0 0], [0 0.14], 'k-', 'LineWidth', 4);   % base up to the shoulder
yline(0, 'k');
hold off;
axis equal;
grid on;
xlabel('Forward (m)');
ylabel('Height (m)');
legend('tip path', 'release','release velocity', 'base', 'Location', 'southoutside');
title('Throw');

subplot(1, 2, 2);
plot(t, phi_cmds' * 180/pi);
xline(t_release, 'r--');
xlabel('Time (s)');
ylabel('Joint angle (deg)');
legend('\phi_1', '\phi_2', '\phi_3', '\phi_4', 'release');
title('Joint angles');
grid on;
%%

if approved
    disp('Trajectory approved, phi_cmds is ready for runTraj');
    fprintf('Move the arm to the start pose first: %s rads\n', mat2str(round(phi_cmds(:,1), 4)));
else
    disp('Trajectory NOT approved, fix it before running on the arm');
end

disp(mat2str(round(phi_cmds,5)));