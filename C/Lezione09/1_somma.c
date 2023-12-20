#include <stdio.h>

int somma(int *, int *);

int main()
{
    int x, y, s;
    printf("Inserisci il primo numero: ");
    scanf("%d", &x);
    printf("Inserisci il secondo numero: ");
    scanf("%d", &y);
    s = somma(&x, &y);
    printf("Somma: %d", s);

    return 0;
}

int somma(int *x, int *y)
{
    return (*x + *y);
}
