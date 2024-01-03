#!/bin/bash

# Es 1 Esame 9 settembre 2021

# Si scriva uno script della shell del_files.sh che prenda come argomento sulla linea di
# comando una stringa ed un percorso, controlli che quest’ultimo corrisponda ad una directory e
# attraversi ricorsivamente il file system a partire da essa, cancellando tutti i file incontrati che abbiano
# come estensione la stringa fornita come primo argomento. Durante la cancellazione deve stampare
# a video il percorso dei file cancellati e, alla fine, deve stampare il numero totale di file rimossi.

# Esempio:
# ./del_files.sh bak .
# ./a.bak
# ./b/c.bak
# Numero di file cancellati: 2

if ! test $# -eq 2
then
    echo "Usage: $0 ext path"
    exit 1
fi

if ! test -d $2
then
    echo "$2 non è una directory accessibile"
    exit 2
fi

num_file=0

# con find attraversa ricorsivamente le directory specificate
# la variabile files contiene tutti i file con estensione specificata
files=`find $2 -name "*.$1"`

for f in $files
do
    if test -f $f
    then
        echo $f
        rm -f $f
        num_file=$[ $num_file+1 ]
    fi
done

echo "Numero di file cancellati: $num_file"

exit 0