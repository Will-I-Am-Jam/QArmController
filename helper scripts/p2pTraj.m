function [phi_cmds, valid] = p2pTraj(P_start, P_end, T_goal, f_cmd)
    %Generates a Trajectory for the QArm between 2 points
    %Inputs
    %   P_start, P_end in m; 
    %   T_goal in s; 
    %   f_cmd in Hz
    %Outputs:
    %   phi_cmds - 4xN joint angle commands (rad), one column per pose
    %   valid - 1xN list of true or false that the pose is within reach

    P_delta = P_end - P_start;
    v = P_delta / T_goal;

    % +1 so both endpoints are included
    numSteps = round(T_goal * f_cmd) + 1; 

    phi_cmds = zeros(4, numSteps);
    valid = false(1, numSteps);

    [phi_cmds(:, 1), valid(1)] = qarmInverseKinematics(P_start, 0);
    for i = 2:numSteps
        t = (i - 1) / f_cmd;
        [phi_cmds(:, i ), valid(i)] = qarmInverseKinematics(P_start + v * t, 0, phi_cmds(:, i-1));
    end    
end