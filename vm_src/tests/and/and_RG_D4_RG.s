.name "zork"
.comment "I'M ALIIIIVE"

l2:		ld %1, r2#enregistre la valeur directe 1 dans r1
		and r2, %:l3, r1#enregistre dans r1 le resultat du and entre la valeur de r2 et la valeur directe a l'adresse de l3
		sti r1, %:l1, %1
		zjmp %:l3

l1:		live %0

l3:		zjmp %:l3
