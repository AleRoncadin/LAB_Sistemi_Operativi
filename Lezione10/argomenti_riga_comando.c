#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    int somma = 0;

    if (argc >= 2 && strcmp(argv[1], "-s") == 0)
        somma = 1;

    int x = 0, y = 0;

    printf("Inserire due numeri: ");
    int n = scanf("%d %d", &x, &y);

    if (somma)
        printf("%d + %d = %d\n", x, y, x + y);
    else
        printf("%d * %d = %d\n", x, y, x * y);

    return 0;
}