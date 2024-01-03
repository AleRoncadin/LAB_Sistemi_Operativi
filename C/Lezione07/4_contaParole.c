#include <stdio.h>

int main()
{
    int c, n = 0;

    printf("Inserisci le parole (termina con Ctrl+D o Ctrl+Z)\n");

    while ((c = getchar()) != EOF)
    {
        if (c ==' ' || c =='\t' || c =='\n')
            n++;
    }

    printf("%d\n", n);

    return 0;
}
