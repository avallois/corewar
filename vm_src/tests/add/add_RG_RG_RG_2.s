.name "zork"
.comment "I'M ALIIIIVE"

#enregistre les valeurs directes 2 et -1 dans les registres r3 et r2
l2:		ld 12, r3#prends les valeurs à l'adresse 12 tel que ca remplisse un D4(car registre prends 4 octets)
		ld %-1, r2#enregistre -1 dans r2
		add r3, r2, r1#additionne r3 et r2 dans r1
		sti r1, %:l1, %1#place r1 à l'addresse resultante de la valeur directe de l'adresse de l1 + 1
		zjmp %:l3

l1:		live %0

l3:		zjmp %:l3

