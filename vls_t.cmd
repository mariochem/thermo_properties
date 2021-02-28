set title "Specific Volume of Saturated Liquid"
set xlabel "Specific Volume(m3/kg)"
set ylabel "Temp(C)"
set grid
plot "pvap.txt" using 3:1 title "SVL" with lines, "pvap.txt" using 3:1 title "Exp." with points
