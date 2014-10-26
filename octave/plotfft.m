% FFT Calculation
%

clc;
clear all;
close all;

content=load('out.txt');
data=complex(content(:,1),content(:,2));

nframes = 4;
unit = 1024;

size = nframes * unit;

v = zeros (size,1);
count = 0;
while (count * unit <= size)
	v(count*unit+1:(count+1)*unit,1) = fft(data(count*unit+1:(count+1)*unit,1));
	count = count + 1;
end
v = abs(fftshift(v));
save -ascii "fft.txt" v


%------eimer-------

%y=fft(data,1024);
%y=fftshift(y);
%plot(abs(y));
%grid on;

%fs=32000;

%y=fft(data,1024);
%y=pwelch(y,1024);
%figure;
%lot(abs(y));
%grid on;

%figure;
%window=hanning(1024);
%overlap=0
%specgram(data, 1024, fs, window, overlap);
%colormap(ocean);

%nframes=size(data,1);

