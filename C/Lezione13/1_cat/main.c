#include "cat.h"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "Uso: ./main file1.txt file2.txt...");
        return 1;
    }

    for (int i = 1; i < argc; i++)
    {
        stampaContenuto(argv[i]);
        printf("\nFINE DI %s\n", argv[i]);
        printf("-----------------------------------------\n");
    }
    return 0;
}


