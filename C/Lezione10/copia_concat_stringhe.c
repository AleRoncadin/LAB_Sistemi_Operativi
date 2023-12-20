#include <stdio.h>
#include <string.h>
#define MAXLEN 20
int main()
{
    char msg[MAXLEN] = "";
    char msg1[MAXLEN] = "Ciao, ";
    char msg2[MAXLEN] = "mondo!";
    strncpy(msg, msg1, MAXLEN);
    strncat(msg, msg2, MAXLEN - strlen(msg) - 1);
    printf("%s\n", msg);
    return 0;
}