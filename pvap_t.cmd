set title "Pressure of Saturated Steam"
set xlabel "Temp(C)"
set ylabel "Pressure(kpa)"
set grid
plot "pvap_t.data" using 1:2 title "Pvap" with lines, "pvap_t.data" using 1:2 title "Exp." with points

set title "Specific Volume of Saturated Liquid"
set xlabel "Temp(C)"
set ylabel "Specific Volume(m3/kg)"
set grid
plot "pvap.txt" using 1:2 title "SVL" with lines, "TVLVG.txt" using 1:2 title "Exp." with points
