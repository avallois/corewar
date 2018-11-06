.name "zork"
.comment "I'M ALIIIIVE"

l2:		or 6, :l3, r1
		sti r1, %1, %:l1
		zjmp %:l3

l1:		live %0

l3:		zjmp %:l3
