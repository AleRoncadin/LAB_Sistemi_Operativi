#include "modifiche.h"

void contaModifiche(char *file, int secondi)
{
    struct stat sb;
    if (stat(file, &sb) == -1)
    {
        fprintf(stderr, "%s:\n", strerror(errno));
        return;
    }

    time_t mtime = sb.st_mtime;
    int count = 0;
    char c;

    printf("Per terminare il programma: EOF\n");

    while((c = getchar()) != EOF)
    {
        if (stat(file, &sb) == -1)
        {
            fprintf(stderr, "%s:\n", strerror(errno));
            return;
        }
        if (sb.st_mtime != mtime)
        {
            ++count;
            printf("Il file %s e’ stato modificato %d volte\n", file, count);
            mtime = sb.st_mtime;
        }
        sleep(secondi);

        
    }
}