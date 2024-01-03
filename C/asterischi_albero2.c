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
            if (i > 0 && i < levels- 1)
            {
                if (k > 0 && k < (2 * i + 1)- 1)
                    printf(" ");
                else
                    printf("*");
            }
            else
                printf("*");
        }
        printf("\n");
    }
    return 0;
}

/* Stampa questo:

-----*
----* *
---*   *
--*     *
-*********

*/