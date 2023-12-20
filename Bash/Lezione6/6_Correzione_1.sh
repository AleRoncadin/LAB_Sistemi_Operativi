#!/bin/bash

if test $# -ne 2
then
    echo "Utilizzo dir1 dir2"
    exit 1
fi

if ! test -d $1 -a -d $2
then
    echo "$1 e $2 devono essere delle directory"
    exit 2
fi

for i in `find $1 -type f`   # oppure for i in $1/*
do
    sed "s/SP/SU/g" "$1" > $2/`basename $i`
done

exit 0