x=1:10;
y=x.^2+1;
plot(x,y);
m=[x',y'];
save test.txt m -ascii 
