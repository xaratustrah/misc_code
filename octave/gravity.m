#!/opt/local/bin/octave -q
% classical equation of motion

clear all;

function dy = f (y,t)

	% Gravitational constant
	G=6.67300e-11; %m^3 kg^-1 s^-2
	
	%Mass of the sun
	m1=1.98892e30;  %kg

	%Mass of the sun by two
	m2=1.98892e30/2;  %kg
	
	dy = [
		y(2)
		G*m2/(y(3)-y(1))^2 
		y(4)
		-G*m2/(y(3)-y(1))^2
	];

endfunction

%distance
au=149.59e9; %in meters

y0 = [ 
	-au
	0 
	au  
	0];
	
t = linspace (0, 1e15, 1e3);
Y=lsode ("f", y0, t);
plot(t,Y(:,1),t,Y(:,3));
grid on;
