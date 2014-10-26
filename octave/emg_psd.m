
% Power Spectral density of the EMG data.
% All frequencies normalized to Pi
% It takes a while to run since the data file is big ;-)

clear all;
load emg.csv;
t = emg(:,1);
x = emg(:,2);
h = spectrum.welch('hamming', 64, 20, 'UserDefined');
hopts1 = psdopts(h, x);
set (hopts1, 'NFFT', 2^14);
hpsd1 = psd (h, x, hopts1);
Pxx1 = hpsd1.data;
W = hpsd1.Frequencies;

% Now we use kaiser window
h.windowName = 'kaiser';
hopts2 = psdopts(h, x);
set (hopts2, 'NFFT', 2^14);
hpsd2 = psd (h, x, hopts2);
Pxx2 = hpsd2.data;

%combine into one vector
hpsd = dspdata.psd([Pxx1, Pxx2], W);

%plot the results

plot(hpsd);
set(gcf, 'Color', [1 1 1]);
legend('Hamming','Kaiser');

% :-)

