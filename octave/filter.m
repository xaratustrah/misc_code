x=load('aktive01_1khz_500mSdiv_200mVdiv.dat');
t=x(:,1)'; y=x(:,2); % exracting columns.

y(y==0)=[]; % removing zeros
t=(0:length(y)-1)'/1000; % defining new time according to new length of y
figure, plot(t,y)

[b,a] = butter(2,[10 490]/(1000/2)); % Butterworth bandpass 10-490Hz order 2*2=4, 1000/2 is for normaliazing to nyquist freq.
y1=filter(b,a,y); % implementing the above filter to y
figure, plot(t,y1)
pwelch(y1,[],[],[],1000) % spctrum of y1

w0 = 50/(1000/2);  bw = w0/35; % 50Hz notch filter with quality factor Q=35.
[bb,aa] = iirnotch(w0,bw);  
fvtool(bb,aa); % using filter visualizing tool to evaluate thie notch filter
y2=filter(bb,aa,y1); % implementing notch filter on y1
figure, plot(t,y2)

z=[t y y1 y2]; % saving results :)
save results.txt z -ascii