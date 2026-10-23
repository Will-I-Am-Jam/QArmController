d = pi/180;
p_des = [0, 0.0822, 0.6947];
phi4 = 0;
phi_ref     = [0; 0; 0; 0]*d;        % joint angles (deg -> rad)
[phi, valid] = qarmInverseKinematics(p_des, phi4, phi_ref)
