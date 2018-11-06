#!/bin/bash

#paths

ASM="/Users/plamusse/Lab/Corewar_vm/asm_src/asm"
FT_ASM="/Users/plamusse/Lab/Corewar_vm/asm_src/tests/asm_diff/asm_zaz"

COR_HEX="/Users/plamusse/Lab/Corewar_vm/asm_src/tests/asm_diff/mycor.hex"
FT_COR_HEX="/Users/plamusse/Lab/Corewar_vm/asm_src/tests/asm_diff/cor.hex"

FILE_PATH=`pwd`

#colors

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

LIST_CHAMPS=$( find . -name "*.s" )

if [ -z "$LIST_CHAMPS" ]
then
	echo "No champion available in this repository"
else
	I=1

	for J in $LIST_CHAMPS
	do
		/bin/echo "$I) $J"
		CHAMP=`echo "$J" | rev | cut -d"." -f2- | rev`
		ASM_FILE=$FILE_PATH/$CHAMP
		ASM_S="$ASM_FILE.s"
		ASM_COR="$ASM_FILE.cor"
		ASM_DIFF="$ASM_FILE.diff"
		CORE_BOOL=0
		FT_CORE_BOOL=0
		$ASM $ASM_S >/dev/null && hexdump -C $ASM_COR > $COR_HEX && CORE_BOOL=1
		$FT_ASM $ASM_S >/dev/null && hexdump -C $ASM_COR > $FT_COR_HEX && FT_CORE_BOOL=1
		if [ $CORE_BOOL = "1" ] && [ $FT_CORE_BOOL = "1" ]
		then
			touch $ASM_DIFF && diff $COR_HEX $FT_COR_HEX > $ASM_DIFF
			if [ -x $ASM_DIFF ]
			then
				echo "Displaying hexadecimal dump comparision:"
				cat $ASM_DIFF
			else
				echo $GREEN"[OK]"$NC
				rm $ASM_DIFF
				rm $ASM_COR
			fi
		elif [ $CORE_BOOL = "0" ] && [ $FT_CORE_BOOL = "0" ]
		then
			echo $RED"[KO]"$NC
		else
			echo "Only one of the executables have not been created"
		fi
		I=$(( I + 1 ))
	done
fi
