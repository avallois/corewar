.name "zork"
.comment "I'M ALIIIIVE"

l2:		ld %1, r2
		xor r2, %2, r1
		sti r1, %:l1, %1
		zjmp %:l3

l1:		live %0

l3:		zjmp %:l3
