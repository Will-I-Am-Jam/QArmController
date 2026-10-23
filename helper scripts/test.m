d = pi/180;
phi     = [0; 0; 0; 0]*d;        % joint angles (deg -> rad)
phi_dot = [0; 0; 0; 0];          % joint speeds (rad/s)
[p4, ~, v4] = qarmForwardKinematics(phi, phi_dot)
