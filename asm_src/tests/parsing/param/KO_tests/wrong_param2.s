.name "zork"
.comment "I'M ALIIIIVE"

l2:		sti r1, r2, %0
		and r1, %0, r1

live:	live r1
		zjmp %:live
