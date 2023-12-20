#include <stdio.h>
#include <stdlib.h>

void reverse(int *array, int size);

void reverse(int *array, int size) {
    int temp;
    for (int i = 0, j = size - 1; i < j; ++i, --j) {
        // Scambia gli elementi ai margini opposti dell'array
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

int main() {
    int size = 10;
    int *array = malloc(size * sizeof(int));
    int read = 0;

    // ciclo che legge i numeri e li memorizza nell'array
    // finché non ci sono errori ( == 1 )
    while (scanf("%d", &array[read]) == 1) {
        if (++read == size) {
            // se read è uguale a size allora abbiamo raggiunto
            // la fine dell'array e bisogna raddoppiare la dimensione
            size *= 2;
            // rialloca dinamicamente la memoria dell'array
            // con la nuova dimensione
            array = realloc(array, size * sizeof(int));
        }
    }

    reverse(array, read); // inverte gli elementi dell'array

    // stampa gli elementi dell'array
    for (int i = 0; i < read; i++) {
        printf("%d\n", array[i]);
    }

    free(array); // libera la memoria di array
    return 0;
}