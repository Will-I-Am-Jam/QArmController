function [phi, valid] = qarmInverseKinematics(p_des, phi4, phi_ref)
%QARMINVERSEKINEMATICS Analytical position inverse kinematics for the QArm.
%   phi = qarmInverseKinematics(p_des) returns the 4-by-1 vector of physical
%   QArm joint angles (rad) that places the end-effector at p_des, a 3-by-1
%   position (m) in frame {0}. This is the inverse of the position output
%   p4 of qarmForwardKinematics.
%   phi4 sets the wrist angle (rad). The wrist only rolls the gripper about
%   its own axis, so it does not change the position. Default is 0.
%   phi_ref is a 4-by-1 reference pose (rad), normally the current joint
%   angles. Up to four solutions exist (base facing toward or away from the
%   target, elbow up or down). The one inside the joint limits that is
%   closest to phi_ref is returned. Default is the home pose, zeros(4,1).
%   valid is false if p_des is out of reach or every solution breaks a
%   joint limit. In that case phi is returned as phi_ref so the arm holds
%   its pose.
%#codegen

if nargin < 2
    phi4 = 0;
end
if nargin < 3
    phi_ref = zeros(4, 1);
end
p_des = p_des(:);
phi_ref = phi_ref(:);

% Manipulator dimensions (m), same as qarmForwardKinematics
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

% Joint limits (rad), same as SpeedControlUsingPosition
phi_min = [-70; -70; -70; -70] * pi/180;
phi_max = [ 70;  70;  70;  70] * pi/180;

phi = phi_ref;
valid = false;

% In the vertical plane of the arm, the forward kinematics are
%   r = l2*sin(phi2 + beta) + l3*cos(phi2 + phi3)   (horizontal reach)
%   h = l2*cos(phi2 + beta) - l3*sin(phi2 + phi3)   (height above shoulder)
% with x = r*cos(phi1), y = r*sin(phi1), z = l1 + h.
r_xy = sqrt(p_des(1)^2 + p_des(2)^2);
h = p_des(3) - l1;

% Base angle. Directly above the base, any phi1 works, so keep phi_ref(1).
if r_xy < 1e-9
    base = phi_ref(1);
else
    base = atan2(p_des(2), p_des(1));
end

% Elbow from the law of cosines:
%   r^2 + h^2 = l2^2 + l3^2 + 2*l2*l3*sin(beta - phi3)
k = (r_xy^2 + h^2 - l2^2 - l3^2) / (2*l2*l3);
if abs(k) > 1
    return;   % target is out of reach
end

best_cost = inf;
for s = [1, -1]                             % base facing toward / away from target
    phi1 = wrapAngle(base + (s < 0)*pi);
    r = s*r_xy;                             % reach measured along the arm's plane
    for delta = [asin(k), pi - asin(k)]     % the two elbow branches
        phi3 = wrapAngle(beta - delta);

        % Shoulder: with the elbow fixed, rotate the whole arm onto the target
        a = l2 + l3*sin(delta);
        b = l3*cos(delta);
        phi2 = wrapAngle(atan2(r, h) - atan2(b, a) - beta);

        cand = [phi1; phi2; phi3; phi4];
        if all(cand >= phi_min & cand <= phi_max)
            cost = norm(cand - phi_ref);
            if cost < best_cost
                best_cost = cost;
                phi = cand;
                valid = true;
            end
        end
    end
end
end

function a = wrapAngle(a)
%WRAPANGLE Wrap an angle to the interval [-pi, pi].
a = atan2(sin(a), cos(a));
end
