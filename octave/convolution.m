# plot

ph = 0.4;
t = 0:0.1:100;

x1 = sin(t);
subplot(3,2,1);
plot(x1);

X1 = fftshift(fft(x1));
subplot(3,2,2);
plot(abs(X1));

x2 = sin(t+ph);
subplot(3,2,3);
plot(x2);

X2 = fftshift(fft(x2));
subplot(3,2,4);
plot(abs(X2));

y = conv(x1, x2);
subplot(3,2,5);
plot(y);

Y = fftshift(fft(y));
subplot(3,2,6);
plot(abs(Y));
