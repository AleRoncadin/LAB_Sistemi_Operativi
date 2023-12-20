#!/bin/bash

# Es 2 Esame 9 settembre 2021

# Si supponga che sia stata impostata una variabile di ambiente di nome utente. Si scriva
# un unico comando o pipeline, utilizzando i vari metacaratteri di composizione di comandi della shell,
# che stampi a video la stringa ok (e niente altro) se esiste un utente del sistema con nome di login
# uguale al valore della variabile utente. In caso contrario, il comando o pipeline non deve stampare
# nulla.
# Suggerimento: si ricorra al file /etc/passwd dove ogni linea corrisponde ad un account del sistema
# ed è una successione di campi separati dai due punti (:). Il campo relativo al nome di login è il
# primo.

cat /etc/passwd | cut -d: -f1 | grep "$utente" /etc/passwd 2>&1 >/dev/null && echo "ok"