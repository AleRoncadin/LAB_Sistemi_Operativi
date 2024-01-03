#include <stdio.h>

int main()
{
    long nc = 0;

    while(getchar() != EOF)
    {
        ++nc;
    }

    printf("%ld\n",nc);  // ld sta per long decimal
    return 0;
}