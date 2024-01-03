#include "cmp.h"

void confrontaContenuto(char *f1, char *f2)
{
    FILE *file1 = fopen(f1, "r");
    FILE *file2 = fopen(f2, "r");

    char buffer1[MAXSIZE]; // Buffer per memorizzare la prima linea letta
    char buffer2[MAXSIZE]; // Buffer per memorizzare la seconda linea letta

    if(!file1 || !file2 || file1 == NULL || file2 == NULL)
    {
        perror("Errore nell'apertura dei file\n");
        printf("%s\n", strerror(errno));
        chiudiFile(file1, file2); // chiudi i file

        exit(2);
    }


    char cont1, cont2;
    //while (((cont1 = fgetc(file1)) != EOF) || ((cont2 = fgetc(file2)) != EOF)) // controlla se il file è terminato
    while (fgets(buffer1, sizeof(buffer1), file1) != NULL &&
           fgets(buffer2, sizeof(buffer2), file2) != NULL)
    {
        if (strcmp(buffer1, buffer2) != 0)
        {
            printf("%s\n", buffer1);
            printf("%s\n", buffer2);
            break; // Esci dopo il primo mismatch
        }
    }

    chiudiFile(file1, file2); // chiudi i file
}

void chiudiFile(FILE *f1, FILE *f2)
{
    fclose(f1);
    fclose(f2);
}