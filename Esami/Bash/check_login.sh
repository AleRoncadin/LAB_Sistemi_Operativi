#!/bin/bash

# Es 2 Esame 20 Gennaio 2021

# Si scriva uno script della shell check_login.sh che prenda sulla linea di comando una
# lista arbitraria di stringhe e controlli se ognuna di esse sia un nome di login valido. In caso positivo
# deve stampare lo user ID corrispondente, mentre in caso negativo deve stampare un messaggio che
# indichi che non è un nome di login valido.
# 
# Esempio:
# $ ./check_login.sh ivan gdm system
# ivan ha id 1000
# gdm ha id 121
# system non e’ un nome di login valido
# 
# Suggerimento: si ricorra al file /etc/passwd dove ogni linea corrisponde ad un account del sistema
# ed è una successione di campi separati dai due punti (:). Il nome di login è rappresentato dal primo
# campo, mentre il terzo campo è lo user ID. Ad esempio:
# pippo:x:1017:1019:Pippo,,,:/home/pippo:/bin/bash

n = $ #
for (( i=1; i<=$n; i++))
do
    if grep "^$1:" /etc/passwd 2>/dev/null >/dev/null
    then
        id=`cat /etc/passwd | grep "^$1:" 2>/dev/null | cut -d: -f3`
        echo $1 ha id $id
    else
        echo "$1 non e’ un nome di login valido "
    fi
    shift
done

exit 0