#include <stdio.h>

int main()
{
    int c, n;

    printf("Inserisci le parole (termina con Ctrl+D o Ctrl+Z)\n");

    while ((c = getchar()) != EOF)
    {
        if (c !=' ' && c !='\t' && c !='\n')
            n++;
        else
        {
            for (int i = 0; i < n; i++)
                putchar('-');
            if (n > 0)
                putchar('\n');
            n = 0;
        }
    }

    return 0;
}
