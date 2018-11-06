.name			"Spaceborg"
		 .comment		 		 "Un champion au comment dans l'espace"	 	 

l2:		sti r1, %:live, %1
		and r1, %0, r1

live:	live %1
		zjmp %:live
