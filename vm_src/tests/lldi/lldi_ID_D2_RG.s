.name "zork"
.comment "I'M ALIIIIVE"

l2:		lldi :l1, %65, r1
		sti r1, %1, %:l1
		zjmp %:l3

l1:		live %0

l3:		zjmp %:l3
