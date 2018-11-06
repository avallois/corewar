.name "zork"
.comment "I'M ALIIIIVE"

l2:		and %9, %:l3, r1#effectue un and entre la valeur directe 9 et la valeur directe à l'adresse de la valeur à l'addresse de l3 soit 8 and 1a et enregistre dans r1
		sti r1, %1, %:l1
		zjmp %:l3

l1:		live %0

l3:		zjmp %:l3
