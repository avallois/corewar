.name "zork"
.comment "I'M ALIIIIVE"

l2:		sti r1, %:live, %123456789123456789132456798
		and r1, %-123456789123456789, r1

live:	live %1
		zjmp %:live
