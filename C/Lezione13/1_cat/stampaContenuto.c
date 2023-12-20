#include "cat.h"

void stampaContenuto(char *name)
{
    FILE *file = fopen(name, "r");

    if (!file)
    {
        fprintf(stderr, "Errore nell'apertura del file: " + *name);
        return;
    }

    char cont;
    while ((cont = fgetc(file)) != EOF) // controlla se il file è terminato
    {
        if (ferror(file))
        {
            fprintf(stderr, "Errore nella lettura del file\n");
            break;
        }
        putchar(cont); // stampa il carattere
    }

    fclose(file); // chiudi il file
}