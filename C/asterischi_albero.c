#include <stdio.h>

int main()
{
    int levels = 5;

    for (int i = 0; i < levels; i++)
    {
        for (int j = 0; j < levels- i; j++)
        {
            printf("-");
        }
        for (int k = 0; k < (2 * i + 1); k++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}

/* Stampa questo:

-----*
----***
---*****
--*******
-*********

*/