#include <stdio.h>
#include <string.h>
#define MAXINPUT 100

// lunghezza delle stringhe
// confronto tra stringhe

// int strlen(char *);
// int strncmp(char *, char *, unsigned);

int main()
{
    char input[MAXINPUT] = "";
    do
    {
        printf("Password: ");
        scanf("%99s", input);
    } while (strncmp(input, "passw0rd", MAXINPUT) != 0);

    printf("Il segreto e': 42\n");
    printf("Lunghezza della stringa: %d", strlen(input));
    return 0;
}

/*int strlen(char *s)
{
    int n = 0;
    for (char *p = s; *p; ++p)
    {
        ++n;
    }
    return n;
}

int strncmp(char *, char *, unsigned)
{
    return 0;
}*/
