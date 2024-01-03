#!/bin/bash

# Esame 06 Febbraio 2018
# 
# si scriva uno script dim.sh della shell che prenda come argomento sulla linea di comando
# il percorso di un file e, se quest’ultimo esiste, è un file regolare ed è leggibile dall’utente, ne stampi
# a video la dimensione in byte e stampi una serie di asterischi di lunghezza pari alla dimensione.
# Esempio (si supponga che il file indice . txt sia lungo 7 byte):
# > ./ dim . sh indice . txt
# Dimensione di indice . txt : 7 byte
# *******

if test $ # - ne 1
then
    echo "Utilizzo: $0 <file>"
    exit 1
fi

if test -f $1 -a -r $1
then
    dim = `wc -c < $1`  # ottengo la dimensione in byte
    echo "Dimensione di $1: $dim byte"

    i=0;

    while test $i -lt $dim
    do
        echo -n "*"
        i=$[ $i+1 ]
    done

    if test $dim -gt 0
    then
        echo
    fi
    
else
    echo "Il file passato da linea di comando deve esistere, essere leggibile ed essere regolare."
    exit 2
fi

exit 0