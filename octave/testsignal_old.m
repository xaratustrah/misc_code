% Generate a signal 
% taken from matlab help

clear all;
clc;
close all;

Fs = 1000;                    % Sampling frequency 1kHz
T = 1/Fs;                     % Sample time
L = 1e5;                     % Length of signal
t = (0:L-1)*T;                % Time vector

% Sum of a 50 Hz sinusoid and a 120 Hz sinusoid
%x = 0.7*sin(2*pi*50*t) + sin(2*pi*120*t); 
%y = x + 2*randn(size(t));     % Sinusoids plus noise

%y=cos(2*pi*50*t);
y=sin(2*pi*50*t); % 1 milivolt
%y=1/2*complex(cos(2*pi*50*t),sin(2*pi*50*t));

%plot(Fs*t(1:50),y(1:50)); % in miliseconds
%plot(t(1:50),real(y(1:50))); % in seconds

%title('Signal Corrupted with Zero-Mean Random Noise')
%title('Signal');
%xlabel('time (milliseconds)');

%f= abs(fft(y,1024));
%f=fftshift(f);
%plot(f);

%figure;
NFFT = 2^nextpow2(L); % Next power of 2 from length of y
Y = fft(y,NFFT)/L;

%f = Fs/2*linspace(NFFT/2,1,NFFT/2+1);



f = Fs/2*linspace(0,1,NFFT/2+1);

% Plot single-sided amplitude spectrum.
%plot(f,2*abs(Y(1:NFFT/2+1))) % DC part unchanged
%title('Single-Sided Amplitude Spectrum of y(t)')
%xlabel('Frequency (Hz)')
%ylabel('|Y(f)|')
%position = get (gcf, "position");
%set (gcf, "position", position + [0.1, 0.105, -.105 -.105]);
        
%figure;
% Plot single-sided power spectrum.
plot(f,2*abs(Y(1:NFFT/2+1)).^2); % DC part unchanged
title('Single-Sided Power Spectrum of y(t)');
xlabel('Frequency (Hz)');
ylabel('|Y(f)|^2');
