.name "zork"
.comment "I'M ALIIIIVE"

l1:
l4:
l5:
l6:
l2:		sti r1, %:l1, %1
		and r1, %0, r1

live:	live %1
		zjmp %:l3
l3:
