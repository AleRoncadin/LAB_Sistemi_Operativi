#!/bin/bash

# Progettare uno script drawsquare che prende in input un
# parametro intero con valore da 2 a 15 e disegna sullo standard
# output un quadrato (utilizzando i caratteri +, - e |) come nel
# seguente esempio:
# > ./drawsquare 4
# +--+
# |  |
# |  |
# +--+

if [ "$#" -ne 1 ] || [ "$1" -lt 2 ] || [ "$1" -gt 15 ]; then
    echo "Inserire un numero compreso compreso tra 2 e 15"
    exit 1
else
    size="$1"

    # il numero di + sopra e sotto è sempre 2
    # il numero di - sopra e sotto è sempre size-2 
    numero_meno=$(($size-2))
    numero_righe=$numero_meno
    riga_meno=""
    riga_spazi=""

    for ((i = 1; i <= $numero_meno; i++))
    do
        riga_meno="$riga_meno-"
        riga_spazi="$riga_spazi "
    done


    riga_sopra_sotto="+$riga_meno+"
    righe_intermezzo="|$riga_spazi|"
    
    echo "$riga_sopra_sotto"
    for ((j = 1; j <= $numero_righe; j++))
    do
        echo "$righe_intermezzo"
    done
    echo "$riga_sopra_sotto"
fi
exit 0