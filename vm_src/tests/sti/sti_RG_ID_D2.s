.name "zork"
.comment "I'M ALIIIIVE"

l2:		sti r1, -511, %:l1
		zjmp %:l3

l1:		live %0

l3:		zjmp %:l3
