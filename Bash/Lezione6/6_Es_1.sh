#!/bin/bash

#Progettare uno script che prende in input come parametri i
#nomi di due directory e copia tutti i file della prima nella
#seconda, trasformando tutte le occorrenze della stringa SP in
#SU in ogni file.

if test $# -ne 2
then
    echo 'usage: 6_Es_1.sh <dirpath> <dirpath>'
    exit 1
fi

if [ ! -d "$1" ] || [ ! -d "$2" ]
then
    echo 'usage: 6_Es_1.sh <dirpath> <dirpath>'
    exit 1
else
    for file in "$1"/*
    do
        if [ -f "$file" ]
        then
            filename=$(basename "$file")
            newfile="$2/$filename"
            cp "$file" "$newfile"
            #rename 's/SP/SU/g' "$newfile"
            mv "$newfile" "$(echo "$newfile" | sed 's/SP/SU/')" >/dev/null 2>/dev/null
        fi
    done

    echo "Files copied and 'SP' replaced with 'SU' in $2"
fi