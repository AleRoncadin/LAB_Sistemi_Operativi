/*
Scrivere il codice di un programma C che prenda come argomento sulla linea di comando
il percorso di un file di testo e stampi a video il suo contenuto, applicando il seguente filtro: devono
essere rimossi dal testo tutti i caratteri eccetto le lettere dell’alfabeto (maiuscole e minuscole). Si
gestiscano inoltre gli eventuali errori (numero di argomenti errato, file non leggibile, ecc.).
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s /path/to/file", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if (!file || file == NULL)
    {
        fprintf(stderr, "File non accessibile");
        return 2;
    }

    int c;
    while ((c = fgetc(file)) != EOF) // controlla se il file è terminato
    {
        if (ferror(file))
        {
            fprintf(stderr, "Errore nella lettura del file\n");
            return 3;
        }

        if (isalpha(c))
        {
            putchar(c); // stampa il carattere
        }
    }

    fclose(file);
    return 0;
}
