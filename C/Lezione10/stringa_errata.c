#include <stdio.h>
#include <string.h>
int main()
{
    char *ciao = "Ciao mondo!";
    strncpy(ciao, "Hello world!", 11);
    printf("%s\n", ciao);
    return 0;
}