cf = 440;                  % carrier frequency (Hz)
sf = 22050;                 % sample frequency (Hz)
d = 1.0;                    % duration (s)
n = sf * d;                 % number of samples
s = (1:n) / sf;             % sound data preparation
s = sin(2 * pi * cf * s) + sin (2 * pi * (cf*2) * s);   % sinusoidal modulation
sound(s, sf);               % sound presentation
% pause(d + 0.5);             % waiting for sound end

A3= 440;
F4= 1.25* A3;
G4= 1.5 * A3;
A4= 2 * A3;
