#include <stdio.h>
#include <math.h>

int lg(int);

int main()
{
    int n = 1000;
    int m = lg(n);

    printf("Vale %d\n", m);
    return 0;
}

int lg(int n)
{
    return (int)log10(n);
}