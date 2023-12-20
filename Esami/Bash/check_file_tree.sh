#!/bin/bash

# Es 1 Esame 20 Gennaio 2021

# Si scriva uno script della shell check_file_tree.sh che prenda come argomento sulla
# linea di comando un percorso, controlli che corrisponda ad una directory e attraversi ricorsivamente
# il file system a partire da essa, stampando alla fine il numero di file e directory incontrati.
# Esempio:
# $ ./check_file_tree.sh /home/ivan
# Numero di file: 65856
# Numero di directory: 5318

if ! test $# -eq 1
then
    echo "Usage: $0 path"
    exit 1
fi

if ! test -d $2
then
    echo "$2 non è una directory accessibile"
    exit 2
fi

num_file=0
num_dir=0

totale=`find $1 -print 2>/dev/null`
for i in $totale
do
    if test -f $i
    then
        num_file=$[ num_file+1 ]
    fi

    if test -d $i
    then
        num_dir=$[ num_dir+1 ]
    fi
done

echo "Numero di file: $num_file"
echo "Numero di directory: $num_dir"

exit 0
