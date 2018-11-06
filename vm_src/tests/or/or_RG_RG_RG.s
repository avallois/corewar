.name "zork"
.comment "I'M ALIIIIVE"

l2:		ld %1, r2
		ld %8, r3
		or r2, r3, r1
		sti r1, %3, %:l1
		zjmp %:l3

l1:		live %0

l3:		zjmp %:l3
