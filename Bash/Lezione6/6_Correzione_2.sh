#!/bin/bash

if test $# -ne 1
then
    echo "Utilizzo dello script: drawsquare <n>"
    exit 1
fi

if test $1 -lt 2 -o $1 -gt 15
then
    echo "Il parametro deve essere un numero >1 e <16"
    exit 2
fi

x=$1
y=$1

while test $y -gt 0
do
    while test $x -gt 0
    do
        if test $x -eq 1 -o $x -eq $1
        then
            if test $y -eq 1 -o $y -eq $1
            then
                echo -n "+"
            else
                echo -n "|"
            fi
        else
            if test $y -eq 1 -o $y -eq $1
            then
                echo -n "-"
            else
                echo -n " "
            fi
        fi

        x=$[$x-1]
    done

    x=$1
    y=$[$y-1]
    echo          # echo singola va a capo

done

exit 0