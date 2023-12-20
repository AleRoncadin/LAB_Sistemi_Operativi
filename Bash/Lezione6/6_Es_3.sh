#!/bin/bash

# Progettare uno script che prende in input come parametro il
# nome di una directory e cancella tutti i file con nome core
# dall’albero di directory con radice la directory parametro.

if [ "$#" -ne 1 ] && [ ! -d "$1" ]; then
    echo "Inserire il nome di una directory"
    exit 1
else
    find $1 -name core -exec rm {} \; 2>/dev/null
fi
exit 0