/*
Esame 13 luglio 2023

Si scriva un programma in C che prenda come argomento sulla linea di
comando il percorso di un file e, se quest’ultimo esiste, è un file regolare, è leggibile dall’utente,
stampi a video il minimo ed il massimo dei numeri che contiene, assumendo che sia costituito soltanto
da interi separati da spazi bianchi (i.e., spazi, tabulazioni, newline).

Esempio, si supponga che il file file . txt contenga quanto segue:
32 45   54
65
    65 778          54
999
-1              -888

allora, l’esecuzione di min_max.sh file.txt deve stampare a video:
Min : -888, Max : 999
*/

#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s /path/to/file\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL)
    {
        fprintf(stderr, "Impossibile aprire il file\n");
        return 2;
    }

    int min, max, i;
    if (fscanf(file, "%d", &i) == 1)
    {
        min = max = i;

        while (fscanf(file, "%d", &i) == 1)
        {
            min = i < min ? i : min;
            max = i > max ? i : max;
        }

        printf("Min: %d, Max: %d\n", min, max);
    }
    else
    {
        fprintf(stderr, "Il file non è nel formato corretto!\n");
        return 3;
    }

    fclose(file);
    return 0;
}