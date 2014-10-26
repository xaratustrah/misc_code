% run in octave
% classical equation of motion

function newton
au=149.60e9; %au in meters

y0 = [
    -au
    0
    au
    0];

t = linspace (0, 1.115e7, 1e4);
%t = 0:0.1:1000;
[T,Y]=ode45(@f,t,y0);
plot(T,Y(:,1),T,Y(:,3));
grid

endfunction

%------------------------------
function dy = f (t,y)

% Gravitational constant
G=6.67300e-11; %m^3 kg^-1 s^-2

%Mass of the sun
m1=1.98892e30;  %kg

%Mass of the sun by two
%m2=1.98892e30/2;  %kg

% collision of two suns

dy = [
    y(2)
    G*m1/(y(3)-y(1))^2
    y(4)
    -G*m1/(y(3)-y(1))^2
    ];
endfunction
