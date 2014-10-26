set key right bottom
set style line 1 lt 3 lw 2 lc rgb "black"
set key box linestyle 1
set title "TTF for a pillbox with r=30 [cm] d = 9 [cm]"
set grid
plot 'mws.txt' using 1:($2/111.279)  lw 2  lc rgb "blue " title "MWS", 'sfish.txt' using 1:4 lc rgb "red" lw 2 title "Superfish"
