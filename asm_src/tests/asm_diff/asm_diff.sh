#!/bin/bash

#paths

ASM="/Users/plamusse/Lab/corewar/asm"
FT_ASM="/Users/plamusse/Lab/corewar/tests/asm_diff/asm_zaz"

COR_HEX="/Users/plamusse/Lab/corewar/tests/asm_diff/mycor.hex"
FT_COR_HEX="/Users/plamusse/Lab/corewar/tests/asm_diff/cor.hex"

FILE_PATH=`pwd`

#booleans

CORE_BOOL=0
FT_CORE_BOOL=0

#colors

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

LIST_CHAMPS=$( ls *.s )

if [ -z "$LIST_CHAMPS" ]
then
	echo "No champion available in this repository"
else
	I=1

	for J in $LIST_CHAMPS
	do
		echo "$I) $J"
		CHAMPS[I]=$J
		I=$(( I + 1 ))
	done
	echo "\n"

	echo "Enter the number of the champion to compare:"
	read CHOOSE_VAR
	CHAMP=`echo "${CHAMPS[CHOOSE_VAR]}" | rev | cut -d"." -f2- | rev`

	if [ -z $CHAMP ]
	then
		echo "The champion you want is space travelling, come back later"
	else
		ASM_FILE=$FILE_PATH/$CHAMP
		ASM_S="$ASM_FILE.s"
		ASM_COR="$ASM_FILE.cor"
		ASM_DIFF="$ASM_FILE.diff"

		echo "Champion choosen: $CHAMP"
		echo "\n"
		echo "Our Assembler:"
		$ASM $ASM_S && hexdump -C $ASM_COR > $COR_HEX && CORE_BOOL=1
		echo "\n"

		echo "Their Assembler:"
		$FT_ASM $ASM_S && hexdump -C $ASM_COR > $FT_COR_HEX && FT_CORE_BOOL=1
		echo "\n"

		if [ $CORE_BOOL = "1" ] && [ $FT_CORE_BOOL = "1" ]
		then
			touch $ASM_DIFF && diff $COR_HEX $FT_COR_HEX > $ASM_DIFF
			if [ -x $ASM_DIFF ]
			then
				echo "Displaying hexadecimal dump comparision:"
				cat $ASM_DIFF
			else
				echo $GREEN"[OK]"$NC
				echo "No differences between the two binaries files"
				rm $ASM_DIFF
				rm $ASM_COR
			fi
		elif [ $CORE_BOOL = "0" ] && [ $FT_CORE_BOOL = "0" ]
		then
			echo $RED"[KO]"$NC
		else
			echo "Only one of the executables have not been created"
		fi
	fi
fi
