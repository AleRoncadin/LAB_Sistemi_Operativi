#!/bin/bash

#Progettare uno script, chiamato listfiles, che prende due
#parametri, una directory e la dimensione di un file in byte. Lo
#script deve fornire il nome di tutti i file regolari contenuti nella
#directory parametro ai quali avete accesso e che sono pi`u piccoli
#della dimensione data. Si controlli che i parametri passati sulla
#linea di comando siano due e che il primo sia una directory.

if test $# -ne 2
then
	echo 'usage: listfiles <dirpath> <dimensione>'
	exit 1
fi
if ! test -d $1
then
	echo 'usage: listfiles <dirpath> <dimensione>'
	exit 2
else
	for i in $1/*
	do
		if test -r $i -a -f $i
		then
			size=`wc -c <$i`
			if test $size -lt $2
			then
				echo `basename $i` has size $size bytes
			fi
		fi
	done
	exit 0	
fi
