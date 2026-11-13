addpath('../');


d = pi/180;
phi     = [0 pi/4 -pi/4 0];        % joint angles (deg -> rad)
phi_dot = [0; 0; 0; 0];          % joint speeds (rad/s)
[p4, ~, v4] = qarmForwardKinematics(phi, phi_dot);
disp(p4);
