%
% TE / TM Mode generator for rectengular resonator
% 04.02.2010
%

clear;
clc;

a=0.45; % in x direction for index m (on the table)
b=0.50; % in y direction for index n (normal table)
d=0.20; % in z direction for index p, along the beam axis (on the table)

mu=pi*4e-7; %VS/A/M
epsilon=8.8541e-12; %AS/V/M
c=299792458; %m/s

fh = fopen ('freq.csv','wt');
disp('Generating frequency Table...');
for m = 1:3
    for n = 1:3
        for p = 0:3
            f=(c/2)*(sqrt((m/a)^2+(n/b)^2+(p/d)^2));
            fprintf(fh, 'f_TM_%d%d%d; %d ; Hz\n',m,n,p,f);
        end
    end
end

f=(c/2)*(sqrt((0/a)^2+(1/b)^2+(1/d)^2));
fprintf(fh, 'f_TE_011; %d ; Hz\n',f);
f=(c/2)*(sqrt((1/a)^2+(0/b)^2+(1/d)^2));
fprintf(fh, 'f_TE_101; %d ; Hz\n',f);

for m = 1:3
    for n = 1:3
        for p = 1:3
            f=(c/2)*(sqrt((m/a)^2+(n/b)^2+(p/d)^2));
            fprintf(fh, 'f_TE_%d%d%d; %d ; Hz\n',m,n,p,f);
        end
    end
end

fclose(fh);
disp('Done.');

% note:
% during the developement of the modes inside the cavity, the larger side
% of the face will be halved first, so this means that if a < b, then after
% the base mode (TM110), TM120 will appear. If a > b then then TM210 will
% appear. But these are actually the same, since you can simply rotate the
% cavity on the table, the base mode won't change! The main differnece is 
% if d is larger than any of a and be, the the base mode changes.
%
