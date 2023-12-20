#!/bin/bash

# Es. 1 Esame 20 Gennaio 2023

# Si scriva uno script della shell check_path che prenda come argomento sulla linea di
# comando una stringa e stampi a video OK se quella stringa coincide con uno dei percorsi elencati
# nella variabile di ambiente PATH. Se non c’è nessuna occorrenza lo script non stampa nulla. Ad
# esempio (supponendo che PATH=/bin:/usr/local/bin):
# > ./check_path /usr/local/bin
# OK
# > ./check_path bin
# >

if test -n "$1"     # controlla se il primo argomento non è vuoto
then
    if echo :$PATH: | grep ":$1:" >/dev/null 2>&1
    then
        echo OK
    fi
fi

# :$PATH: --> concatena i : a inizio e fine di PATH
# ":$1:" --> concatena anche qui i : a inizio e fine dell'argomento
# echo :$PATH: --> stampa a video :$PATH:
# | grep ":$1:" --> cerca :$1: in :$PATH:
# >/dev/null 2>&1 --> impedisce la stampa dell'output e di eventuali errori