.name "zork"
.comment "I'M ALIIIIVE"

l2:		ld %5, r2
		sti r1, r2, %510
		zjmp %:l3

l1:		live %0

l3:		zjmp %:l3
