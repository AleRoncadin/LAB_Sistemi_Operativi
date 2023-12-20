#include "cmp.h"

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("Uso: ./main file1.txt file2.txt...");
        return 1;
    }

    confrontaContenuto(argv[1], argv[2]);
    
    return 0;
}