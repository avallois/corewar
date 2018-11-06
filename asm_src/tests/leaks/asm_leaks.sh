#!/bin/bash

#paths

ASM="/Users/plamusse/Lab/Corewar_vm/asm_src/asm"

FILE_PATH=`pwd`

DEF_ST="definitely lost: 0 bytes in 0 blocks"
#colors

RED='\033[0;31m'
GREEN='\033[0;32m'
L_PURPLE='\033[1;35m'
NC='\033[0m'

LIST_CHAMPS=$( find . -name "*.s" )

if [ -z "$LIST_CHAMPS" ]
then
	echo "No champion available in this repository"
else
	I=1

	for CHAMP in $LIST_CHAMPS
	do
		echo $L_PURPLE
		/bin/echo "$I) $CHAMP"
		echo $NC
		CHAMP=`echo "$CHAMP" | rev | cut -d"." -f2- | rev`
		ASM_S="$CHAMP.s"
		ASM_COR="$CHAMP.cor"
		LEAKS_LOG="$FILE_PATH/leaks.log"
		valgrind --leak-check=full --show-leak-kinds=all $ASM $ASM_S &> $LEAKS_LOG
		DEF[0]=$( grep -e 'definitely lost:' $LEAKS_LOG | cut -f7 -d" " ) 
		DEF[1]=$( grep -e 'definitely lost:' $LEAKS_LOG | cut -f10 -d" " ) 
		if [ ${DEF[0]} == "0" ] && [ ${DEF[1]} == "0" ] 
		then
			DEF_BOOL="1"
		else
			grep -e 'definitely lost' $LEAKS_LOG
			DEF_BOOL="0"
		fi
		IND[0]=$( grep -e 'indirectly lost:' $LEAKS_LOG | cut -f7 -d" " ) 
		IND[1]=$( grep -e 'indirectly lost:' $LEAKS_LOG | cut -f10 -d" " ) 
		if [ ${IND[0]} == "0" ] && [ ${IND[1]} == "0" ] 
		then
			IND_BOOL="1"
		else
			grep -e 'indirectly lost' $LEAKS_LOG
			IND_BOOL="0"
		fi
		if [ $DEF_BOOL == "1" ] && [ $IND_BOOL == "1" ]
		then
			echo $GREEN[OK]$NC
		else
			echo $ASM_S >> $LEAKS_LOG
			echo $RED[KO]$NC
			break
		fi
		rm $ASM_COR &>/dev/null
		rm $LEAKS_LOG &>/dev/null
		I=$(( I + 1 ))
	done
fi
