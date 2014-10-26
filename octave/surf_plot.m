clear all;
load BE.mat;

Zmax=250;
Nmax=250;

surf(BE','EdgeColor','none');
axis xy; 
axis tight; 
colormap(jet);
view(90,-90);
xlabel('Z');
ylabel('N');
zlabel('Binding Energy per Nucleon [MeV]');

[p] = gradient(BE);

%hold on;

% figure;
% surf(gradient(BE'),'EdgeColor','none');
% axis xy; 
% axis tight; 
% colormap(jet);
% view(90,-90);
% xlabel('Z');
% ylabel('N');
% zlabel('Binding Energy per Nucleon [MeV]');
% 
% plot(BE);

figure;
plot(max(BE));

