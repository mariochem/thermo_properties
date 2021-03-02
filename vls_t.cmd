set title "Specific Volume of Saturated Liquid"
set xlabel "Specific Volume(m3/kg)"
set ylabel "Temp(C)"
set grid
set xrange [0.00095:0.0032]
set yrange [0.:380.]
plot "pvap.txt" using 3:1 title "Exp. SVL" with linespoints

