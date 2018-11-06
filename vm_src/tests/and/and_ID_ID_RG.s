.name "zork"
.comment "I'M ALIIIIVE"

l2:		and 7, :l3, r1#enregistre dans r1 le resultat du and entre la valeur a l'adresse de 7 et la valeur a l'adresse de l3
		sti r1, %1, %:l1
		zjmp %:l3

l1:		live %0

l3:		zjmp %:l3
