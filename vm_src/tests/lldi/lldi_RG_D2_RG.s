.name "zork"
.comment "I'M ALIIIIVE"

l2:		ld 6, r2
		lldi r2, %:l1, r1
		sti r1, %1, %:l1
		zjmp %:l3

l1:		live %0

l3:		zjmp %:l3
