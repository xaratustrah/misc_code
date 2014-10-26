set palette defined (0 0.0 0.0 0.5, \
1 0.0 0.0 1.0, \
2 0.0 0.5 1.0, \
3 0.0 1.0 1.0, \
4 0.5 1.0 0.5, \
5 1.0 1.0 0.0, \
6 1.0 0.5 0.0, \
7 1.0 0.0 0.0, \
8 0.5 0.0 0.0 )

set xlabel "xoffset"
set ylabel "yoffset"
unset key
plot 'results.txt' using 2:1:3 with image

set pm3d
set palette rgb 33,13,10
set view map
splot 'file.xyz' with points palette pt 5 ps 0.5
