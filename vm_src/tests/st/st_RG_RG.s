.name "zork"
.comment "I'M ALIIIIVE"

l2:		ld 5, r3
		st r1, r3
		sti r1, %:l1, %1
		zjmp %:l3

l1:		live %0

l3:		zjmp %:l3

