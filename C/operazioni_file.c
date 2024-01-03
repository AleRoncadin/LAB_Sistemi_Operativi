/* Es. 2 Esame 20 Gennaio 2023

 Scrivere il codice di uno script della shell bash che prenda come parametro sulla linea di
 comando un percorso di un file di testo. Quest’ultimo deve essere composto da linee contenenti un
 carattere (fra +, −, ∗, /) e due interi, separati da virgole, ad esempio:
 *,56,89
 -,120,-1
 +,12,12
 +,30,5
 /,5,2
 Lo script deve leggere linea per linea il file e stampare a video il risultato dell’operazione, indicata
 dal carattere ad inizio linea, sui due numeri interi. Ad esempio per il caso precedente:
 4984
 121
 24
 35
 2
 Si gesticano eventuali errori dovuti al parametro mancante o alla non esistenza/accessibilità in lettura
 del file.
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s /percorso/file", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], 'r');

    if (file == NULL)
    {
        fprintf(stderr, "File non accessibile");
        return 2;
    }

    char c;
    int x, y;
    while (fscanf(file, "%c,%d,%d", &c, &x, &y) == 3)
    {
        switch (c)
        {
        case '+':
            printf("%d\n", x + y);
            break;
        case '-':
            printf("%d\n", x - y);
            break;
        case '*':
            printf("%d\n", x * y);
            break;
        case '/':
            printf("%d\n", x / y);
            break;
        }
    }

    fclose(file);
    
    return 0;
}