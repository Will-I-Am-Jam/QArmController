function [phi] = runTraj(phi_cmds, f_cmd, Ts, start)
%#codegen
% Plays back a joint trajectory (e.g. from p2pTraj) one command at a time.
% Call once per sample. Each column of phi_cmds is held for 1/f_cmd s,
% then the next column is sent. The last column is held at the end.
%
% Inputs:
%   phi_cmds - 4xN joint angle commands (rad), one column per step
%   f_cmd    - rate the commands were generated at (Hz), must be <= 1/Ts
%   Ts       - sample time of the block (s)
%   start    - column of phi_cmds to begin at (default 1)
% Output:
%   phi      - 4x1 joint angle command for this sample (rad)
    if(nargin < 4)
        start = 1;
    end

    N = size(phi_cmds, 2);

    persistent idx
    persistent count
    if isempty(idx)
        idx = min(max(round(start), 1), N);   % begin at the start column
        count = 0;
    end

    phi = phi_cmds(:, idx);

    % move to the next column every 1/f_cmd seconds, hold it in between
    n_steps = max(1, round(1/(f_cmd*Ts)));
    count = count + 1;
    if count >= n_steps
        count = 0;
        idx = min(idx + 1, N);   % stay on the last column once finished
    end
end
