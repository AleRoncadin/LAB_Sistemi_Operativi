/*
Esame 06 Febbraio 2018

Scrivere il codice di un programma C che riceva in input una lista di n parole e stampi a
video tali parole in ordine lessicografico. Si gestisca a scelta (motivata) il formato di input/output.
Ad esempio (se es è il nome del programma eseguibile):
$ ./es l3xixograph 0rd3r WORDS aRe 0rd3r3d bas3d on THE az order of their c0mp0nents
un possibile output è:
$ 0rd3r, 0rd3r3d, aRe, az, bas3d, c0mp0nents, l3xixograph, of, on, order, THE, their, WORDS
*/

#include <stdio.h>
#include <string.h>
#define MAXINPUT 100

int main(int argc, char **argv)
{
    int i, j;
    char *temp;

    if (argc < 2)
    {
        fprintf(stderr, "Utilizzo : % s stringa1 stringa2 ...\n", argv[0]);
        return 1;
    }

    for (i = 1; i < argc - 1; ++i)
    {
        for (j = i + 1; j < argc; ++j)
        {
            if (strncmp(argv[i], argv[j], MAXINPUT) > 0)
            {
                temp = argv[i];
                argv[i] = argv[j];
                argv[j] = temp;
            }
        }
    }

    printf("\nIn lexicographical order:\n");
    for (i = 1; i < argc; ++i)
    {
        printf("%s, ", argv[i]);
    }

    return 0;
}