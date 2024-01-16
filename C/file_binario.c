#include "binario.h"

int main(int argc, char **argv)
{
    FILE *file = fopen("/dev/urandom", "rb");

    if (!file || file == NULL)
    {
        printf("%s\n", strerror(errno));
        fclose(file);
        return 1;
    }

    int array[10]; // Array per memorizzare gli interi letti

    // Legge 10 interi e li memorizza nell'array
    size_t elements_read = fread(array, sizeof(int), 10, file);

    if (elements_read != 10)
    {
        fprintf(stderr, "Errore nella lettura del file");
        fclose(file);
        return 2;
    }

    // Stampa gli interi letti
    for (int i = 0; i < 10; ++i)
    {
        printf("%d\n", array[i]);
    }

    fclose(file);

    return 0;
}