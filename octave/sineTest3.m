function main
Fs=20;      % sampling Freq (Hz)
Tlim=20;	% duration (sec)
Ai=1;       % initial amplitude fur peaks
Bi=2;       % initial amplitude fur valleys
f=.5;       % wave freq (Hz)

T=1/Fs;     % period
t=0:T:Tlim; % time vector
w=2*pi*f;   % omega

At=Ai*funA(w,t/Tlim);	% peak envelop
Bt=Bi*funB(w,t/Tlim);	% valley envelop

y=sin(w.*t);            % intact wave

y=y.*At.*(y>0) + y.*Bt.*(y<0);  % manipulating positive and negative parts, separately.

figure; plot(t,y,t,At,t,-Bt);   % plot

function y=funA(w,x)
% y=1-x;
%y=(1-x).^2;
%y=x.^2;
%y=1-x.^2;
y=sin(1*w*x);

function y=funB(w,x)
y=1-x;
%y=(1-x).^2;
%y=x.^2;
%y=1-x.^2;
%y=sin(1*w*x);


