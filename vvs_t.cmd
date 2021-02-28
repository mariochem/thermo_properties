set title "Specific Volume of Saturated Vapor"
set xlabel "Specific Volume(m3/kg)"
set ylabel "Temp(C)"
set grid
plot "pvap.txt" using 4:1 title "SVL" with lines, "pvap.txt" using 4:1 title "Exp." with points
