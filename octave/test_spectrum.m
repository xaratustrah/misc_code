clear all;

disp('wait...');
[z,Z_full,fs,fc,header] = iqtread_oct('pm2_rsa_02976_20100421-061139-3498057310.iqt');

%fft file

framewidth=1024
nframes = 500
%nframes=sizeof(z)/framewidth;
%npoints = length(Z_full);
npoints=nframes*framewidth

fid1 = fopen ('newfile.psd.asc', "w");
fid2 = fopen ('newfile.psd.bin', "w");

disp 'Writing fft file...';
disp 'ASCII and Binary files contains power spectrum in dBm';


%mag=real(Z_full).^2+imag(Z_full).^2;
mag=abs(fftshift(Z_full)).^2;
mag_dbm=10*log10(mag/0.001);


for k=1:npoints
	fprintf(fid1,'%d\n',mag_dbm(1,k));
	fwrite(fid2,mag_dbm(1,k),"double");
	printf('Progress : %d %%\r', k * 100 / npoints);

end

printf('\n');
fclose (fid1);
fclose (fid2);
