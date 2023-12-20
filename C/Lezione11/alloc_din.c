#include <stdio.h>
#include <stdlib.h>

int somma(int *array, int size)
{
    int s = 0;
    for (int i = 0; i < size; i++)
        s += array[i];
    return s;
}

int main()
{
    int n = 0;

    printf("Quanti numeri verranno inseriti? ");
    scanf("%d", &n);

    if (n == 0)
        return 0;

    // alloca dinamicamente un vettore di interi di n elementi
    // n * sizeof(int): dimensione totale in byte per mem. n interi
    
    int *elementi = malloc(n * sizeof(int));

    printf("Inserire i numeri: ");

    for (int i = 0; i < n; ++i)
        scanf("%d", elementi + i);

    printf("La somma dei numeri inseriti e’: %d\n", somma(elementi, n));
    
    // libera la zona di memoria allocata dinamicamente
    free(elementi);

    return 0;
}