.name "zork"
.comment "I'M ALIIIIVE"

l2:		lld :l1, r2
		sti r1, r2, %1
		zjmp %:l3

l1:		live %0

l3:		zjmp %:l3
