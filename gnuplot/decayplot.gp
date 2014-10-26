#!/opt/local/bin/gnuplot

#set multiplot layout 1, 2 
set title "Decay curve with gas target"# font "Helvetica,24"
#set tmargin 2
set grid
set xlabel "Frames" # font "Helvetica,20"
set ylabel "Sigma" # font "Helvetica,20"
#set log x
#set xrange [1:100]
set key box linestyle 0

# -- new plot
set term aqua 0
#set term push
#set term pdf #monochrome
#set out '../report/heburn_metal5_mod.pdf'
#set log y
#plot \
"x-time.dat" using ($1*31536000):276 lw 2 with line title "78-Kr"
#set term pop
#plot 'beta1.txt' with lines title "beta = 1", 'beta071.txt' with lines lc rgb "blue" title "beta = 0.7"
plot "results.txt" with errorbars