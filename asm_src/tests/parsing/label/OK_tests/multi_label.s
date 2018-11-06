.name "zork"
.comment "I'M ALIIIIVE"

l1:
l2:		sti r1, %:l1, %1
		and r1, %0, r1

live:	live %1
		zjmp %:live
