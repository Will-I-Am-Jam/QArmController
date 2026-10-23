function [phi] = runTraj(phi_cmds, f_cmd, Ts, start, enable, reverse)
%#codegen
% Plays back a joint trajectory (e.g. from p2pTraj) one command at a time.
% Call once per sample. Each column of phi_cmds is held for 1/f_cmd s,
% then the next column is sent. The end column (last when playing
% forward, first in reverse) is held once it is reached.
%
% Inputs:
%   phi_cmds - 4xN joint angle commands (rad), one column per step
%   f_cmd    - rate the commands were generated at (Hz), must be <= 1/Ts
%   Ts       - sample time of the block (s)
%   start    - column of phi_cmds to begin at (default 1)
%   enable   - 1 plays the trajectory, 0 pauses it and holds the current
%              command; playback resumes from there when enable returns
%              to 1 (default 1)
%   reverse  - 0 plays forward (toward column N), 1 plays backward (toward
%              column 1) from the current column; can be switched while
%              running (default 0)
% Output:
%   phi      - 4x1 joint angle command for this sample (rad)
    if(nargin < 4)
        start = 1;
    end
    if(nargin < 5)
        enable = 1;
    end
    if(nargin < 6)
        reverse = 0;
    end

    N = size(phi_cmds, 2);

    persistent idx
    persistent count
    if isempty(idx)
        idx = min(max(round(start), 1), N);   % begin at the start column
        count = 0;
    end

    phi = phi_cmds(:, idx);

    % paused: hold the current command and don't advance
    if enable < 0.5
        return;
    end

    % move to the next column every 1/f_cmd seconds, hold it in between
    n_steps = max(1, round(1/(f_cmd*Ts)));
    count = count + 1;
    if count >= n_steps
        count = 0;
        if reverse > 0.5
            idx = max(idx - 1, 1);   % stay on the first column once back
        else
            idx = min(idx + 1, N);   % stay on the last column once finished
        end
    end
end
