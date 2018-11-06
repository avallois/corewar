.name "zork"
.comment "I'M ALIIIIVE"

l2:		fork %0 #DANS CE CAS CETTE AFFIRMATION EST INVALIDE: Le nouveau processus garde donc l'etat de tout les registres et du carry, seul le PC differe
		zjmp %:l3

l1:		live %0

l3:		zjmp %:l3
