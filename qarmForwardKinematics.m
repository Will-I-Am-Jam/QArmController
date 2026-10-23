function [p4, R04, v4, omega4, J] = qarmForwardKinematics(phi, phi_dot)
%QARMFORWARDKINEMATICS Compute the QArm end-effector pose and velocity.
%   phi is the 4-by-1 vector of physical QArm joint angles (rad).
%   phi_dot is the 4-by-1 vector of physical joint velocities (rad/s).
%   p4 is the end-effector position (m) in frame {0}, and R04 is its
%   orientation. v4 is the linear velocity of p4 (m/s), and omega4 is
%   the end-effector angular velocity (rad/s), both expressed in frame {0}.
%   J is the 6-by-4 geometric Jacobian: [v4; omega4] = J*phi_dot.
%   The original call [p4, R04] = qarmForwardKinematics(phi) still works.
%   If phi_dot is omitted, v4 and omega4 are returned as empty arrays.

validateattributes(phi, {'numeric'}, {'real', 'finite', 'vector', 'numel', 4}, ...
    mfilename, 'phi', 1);
phi = phi(:);
if nargin >= 2
    validateattributes(phi_dot, {'numeric'}, ...
        {'real', 'finite', 'vector', 'numel', 4}, mfilename, 'phi_dot', 2);
    phi_dot = phi_dot(:);
end

% Manipulator dimensions (m)
L1 = 0.1400;
L2 = 0.3500;
L3 = 0.0500;
L4 = 0.2500;
L5 = 0.1500;

% Equivalent geometric parameters
l1 = L1;
l2 = sqrt(L2^2 + L3^2);
l3 = L4 + L5;
beta = atan(L3/L2);

% Convert the physical joint coordinates phi to DH coordinates theta.
theta = phi;
theta(1) = phi(1);
theta(2) = phi(2) + beta - pi/2;
theta(3) = phi(3) - beta;
theta(4) = phi(4);

% Standard DH table:
% i       a_i       alpha_i       d_i       theta_i
% 1        0          -pi/2        l1        theta(1)
% 2        l2          0            0        theta(2)
% 3        0          -pi/2         0        theta(3)
% 4        0           0            l3       theta(4)
T01 = quanser_arm_DH(0,  -pi/2, l1, theta(1));
T12 = quanser_arm_DH(l2,  0,     0, theta(2));
T23 = quanser_arm_DH(0,  -pi/2,  0, theta(3));
T34 = quanser_arm_DH(0,   0,    l3, theta(4));

T02 = T01*T12;
T03 = T02*T23;
T04 = T03*T34;

p4 = T04(1:3, 4);
R04 = T04(1:3, 1:3);

% Joint i rotates about z_{i-1}. Express each axis and origin in frame {0}.
p0 = [0; 0; 0];
p1 = T01(1:3, 4);
p2 = T02(1:3, 4);
p3 = T03(1:3, 4);
z0 = [0; 0; 1];
z1 = T01(1:3, 3);
z2 = T02(1:3, 3);
z3 = T03(1:3, 3);

% Revolute-joint Jacobian columns: z_{i-1} cross (p4 - p_{i-1}).
% The DH angles differ from phi only by constant offsets, so
% theta_dot = phi_dot and no additional coordinate conversion is needed.
Jv = [cross(z0, p4-p0), cross(z1, p4-p1), ...
      cross(z2, p4-p2), cross(z3, p4-p3)];
Jw = [z0, z1, z2, z3];
J = [Jv; Jw];

if nargin >= 2
    v4 = Jv*phi_dot;
    omega4 = Jw*phi_dot;
else
    v4 = [];
    omega4 = [];
end
end

function T = quanser_arm_DH(a, alpha, d, theta)
%QUANSER_ARM_DH Standard DH homogeneous transform.
T_R_z = [cos(theta), -sin(theta), 0, 0;
         sin(theta),  cos(theta), 0, 0;
         0,           0,          1, 0;
         0,           0,          0, 1];

T_T_z = [1, 0, 0, 0;
         0, 1, 0, 0;
         0, 0, 1, d;
         0, 0, 0, 1];

T_T_x = [1, 0, 0, a;
         0, 1, 0, 0;
         0, 0, 1, 0;
         0, 0, 0, 1];

T_R_x = [1, 0,          0,           0;
         0, cos(alpha), -sin(alpha), 0;
         0, sin(alpha),  cos(alpha), 0;
         0, 0,           0,           1];

T = T_R_z*T_T_z*T_T_x*T_R_x;
end
