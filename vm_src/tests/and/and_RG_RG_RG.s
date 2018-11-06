.name "zork"
.comment "I'M ALIIIIVE"

l2:		ld %6, r2#enregistre la valeur 6 dans r2
		ld 5, r3#enregistre les valeurs directes à l'adresse 5 telle que ca remplisse un D4(taille registre)soit 060202d0 (60202d pour la calculatrice)
		and r2, r3, r1#enregistre dans r1 le resultat du and entre r1 et r2
		sti r1, %1, %:l1
		zjmp %:l3

l1:		live %0

l3:		zjmp %:l3
