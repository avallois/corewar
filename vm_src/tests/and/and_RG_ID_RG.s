.name "zork"
.comment "I'M ALIIIIVE"

l2:		ld %1, r2
		and r2, 5, r1#enregistre dans r1 le resultat du  and entre la valeur dans r2 et la valeur à l'adresse 5
		sti r1, %:l1, %1
		zjmp %:l3

l1:		live %0

l3:		zjmp %:l3
