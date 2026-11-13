function [phi_cmds, valid] = waypointTraj(P_goals,T_goals, f_cmd)
    %P goals is a 3xN matrix

    numGoals = width(P_goals);
    phi_cmds = [];
    valid = [];

    if(numGoals < 2)
        disp("provide atleast 2 goals");
        return
    end

    for i = 1:(numGoals - 1)
        [leg_phi, leg_valid]= p2pTraj(P_goals(:, i), P_goals(:, i+1), T_goals(i), f_cmd);
        if i > 1
            % first point of this leg is the last point of the previous one
            leg_phi = leg_phi(:, 2:end);
            leg_valid = leg_valid(2:end);
        end
        phi_cmds = [phi_cmds, leg_phi];
        valid = [valid, leg_valid];
    end

end