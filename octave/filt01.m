n = 0:56;
hd = +sin (15 * pi / 56*(n-28))./(pi*(n-28))-sin (11*pi/14*(n-28))./(pi*(n-28));
hd(29) = 1 + 15/56 - 11/14;
h = hd .* bartlett(57).';
Fh = fft (h);
w = linspace (0,2,58);
plot (w(1:57), abs (Fh));
