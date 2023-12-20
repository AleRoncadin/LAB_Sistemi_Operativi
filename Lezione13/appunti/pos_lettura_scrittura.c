#include <stdio.h>
#include <errno.h>
#include <string.h>

// Programma per conoscere la lunghezza di un file in bytes
int main(int argc, char **argv)
{
    char *filename = argv[1];

    FILE *file = fopen(filename, "r");
    if (!file)
    {
        fprintf(stderr, "%s: Impossibile aprire il file %s: %s",
                argv[0], filename, strerror(errno));
        return 2;
    }

    fseek(file, 0, SEEK_END); // 0 byte dalla fine del file
    long bytes = ftell(file);

    printf("Il file e’ lungo %ld bytes\n", bytes);
    fclose(file);

    return 0;
}