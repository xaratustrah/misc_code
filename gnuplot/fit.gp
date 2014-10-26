set title "Exponential Decay Fit"
set grid
set xlabel "Time [s]"
set ylabel "No of occurance"

binwidth=5
#bin(x,width)=width*floor(x/width)
bin(x,width)=width*floor(x/width) + binwidth/2
set boxwidth binwidth
plot '142pm_sim.txt' using (bin($1,binwidth)):(1.0) smooth freq with boxes

f(x) = a * exp (-x*b)

fit f(x) 'blah.txt' via a,b,c

plot f(x), 'blah.txt'

plot 'blah.txt' using 1:($2/580)

set table 'new.txt'