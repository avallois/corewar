.name "zork"
.comment "I'M ALIIIIVE"

l2:		sti r1, %:live2, %0
l2:		sti r1, %:live4, %0
		and r1, %0, r1

live:	live %1
		zjmp %:live
live2:
live3:
