.name "zork"
.comment "I'M ALIIIIVE"

l2:		sti r1, %:li%ve, %0
		and r1, %0, r1

live:	live %1
		zjmp %:live

li%ve: