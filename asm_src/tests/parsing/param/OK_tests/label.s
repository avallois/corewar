.name "zork"
.comment "I'M ALIIIIVE"

live2:

l2:		sti r1, %:live, %0
		and r1, %0, r1

live:	live %1
		zjmp %:live2
