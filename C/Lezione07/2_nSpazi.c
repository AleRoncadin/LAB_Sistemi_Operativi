#include <stdio.h>

int main()
{
    long n = 0;
    int c;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t' || c == '\n')
        {
            ++n;
        }
    }
    
    printf("\n%ld\n", n);
    return 0;
}
