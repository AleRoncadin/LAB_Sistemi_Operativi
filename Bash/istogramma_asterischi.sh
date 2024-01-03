#!/bin/bash

# Esame 30 gennaio 2015

# Si predisponga uno script della shell che legga da riga di comando una successione di numeri
# interi positivi terminata da -1. Lo script deve poi produrre sullo standard output un istogramma
# (utilizzando ad esempio il carattere *) tale che ogni linea sia lunga quanto il corrispondente numero
# della successione ricevuta in input (escluso il terminatore -1 ovviamente). Si ignori la gestione degli
# eventuali errori. Esempio:

# > ./istog.sh 3 5 1 6 -1
# ***
# *****
# *
# ******

if ! test $# -eq 0
then
    echo "Usage: $0 numbers... -1"
    exit 1
fi

n=$1    # n è il primo argomento

while ! test $n -eq -1      # ripeti il ciclo finché l'argomento è -1
do
    i=0
    while test $i -lt $n
    do
        echo -n '*'     # -n per non andare a capo
        i=$[ $i+1 ]
    done

    echo
    shift # Sposta tutti gli argomenti in avanti ($2 diventa $1, $3 diventa $2...)
    n=$1
done

exit 0