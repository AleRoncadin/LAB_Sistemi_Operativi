// Esame 30 gennaio 2015
// 
// Si predisponga uno script della shell che legga da riga di comando una successione di numeri
// interi positivi terminata da -1. Lo script deve poi produrre sullo standard output un istogramma
// (utilizzando ad esempio il carattere *) tale che ogni linea sia lunga quanto il corrispondente numero
// della successione ricevuta in input (escluso il terminatore -1 ovviamente). Si ignori la gestione degli
// eventuali errori. Esempio:
// 
// > ./istog.exe 3 5 1 6 -1
// ***
// *****
// *
// ******

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if(argc < 2 || atoi(argv[argc - 1]) != -1)
    {
        fprintf(stderr, "Usage: %s 1 4 8 -1\n", argv[0]);
        exit(1);
    }

    for(int i = 1; i < argc - 1; i++)   // Cicla fino al penultimo elemento
    {
        int n = atoi(argv[i]); // Converti l'argomento in un intero

        for(int j = 0; j < n; j++)
        {
            putchar('*');
        }
        putchar('\n');
    }
    
    return 0;
}
