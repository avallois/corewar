.name "Nospaceborg"
.comment "A shittily intended program"

ste r1, %:line, %1

l2:sti r1,%:live,%1#comment
#comment
and r1,%0, r1   		 	#comment
live:live%1
zjmp%:live
#comment
