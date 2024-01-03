#include "binario.h"

int main(int argc, char **argv)
{
    int file = open("/dev/urandom", O_RDONLY, 0444);
    
    if(file == -1) 
    {
        printf("%s\n", strerror(errno));
        close(file);
        return 1;
    }
    
    int array[10];

    ssize_t elements = read(file, array, sizeof(int) * 10);

    if (elements != sizeof(int) * 10) {
        fprintf(stderr, "Errore nella lettura del file");
        close(file);
        return 2;
    }

    // Stampa gli interi letti
    for (int i = 0; i < 10; ++i) {
        printf("%d\n", array[i]);
    }

    return 0;
}