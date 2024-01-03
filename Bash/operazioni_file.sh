#!/bin/bash

# Es. 2 Esame 20 Gennaio 2023

# Scrivere il codice di uno script della shell bash che prenda come parametro sulla linea di
# comando un percorso di un file di testo. Quest’ultimo deve essere composto da linee contenenti un
# carattere (fra +, −, ∗, /) e due interi, separati da virgole, ad esempio:
# *,56,89
# -,120,-1
# +,12,12
# +,30,5
# /,5,2
# Lo script deve leggere linea per linea il file e stampare a video il risultato dell’operazione, indicata
# dal carattere ad inizio linea, sui due numeri interi. Ad esempio per il caso precedente:
# 4984
# 121
# 24
# 35
# 2
# Si gesticano eventuali errori dovuti al parametro mancante o alla non esistenza/accessibilità in lettura
# del file.

if ! test $# -eq 1
then
    echo "Usage: $0 /percorso/file"
    exit 1
fi

if ! test -r $1
then
    echo "$1 non è un file leggibile"
    exit 2
fi

num_linee=`cat $1 | wc -l`  # numero linee
i=1

while test $i -le $num_linee
do
    linea=`cat $1 | head -n +$i | tail -1`  # restituisce solo la riga interessata
    op=`echo $linea | cut -d',' -f1`
    n1=`echo $linea | cut -d',' -f2`
    n2=`echo $linea | cut -d',' -f3`
    echo $[ $n1 $op $n2 ]
    i=$[ $i+1 ]
done

exit 0


