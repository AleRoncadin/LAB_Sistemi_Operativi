#include <stdio.h>

int isWhiteSpace(int c)
{
    if(c == ' ' || c == '\t' || c == '\n')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    long n = 0;
    int c;

    while((c = getchar()) != EOF)
    {
        if(isWhiteSpace(c))
        {
            ++n;
        }
    }

    printf("\n%ld\n", n);
    return 0;
}