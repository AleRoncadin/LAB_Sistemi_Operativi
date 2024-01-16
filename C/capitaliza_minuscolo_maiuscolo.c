#include <stdio.h>
#include <ctype.h>

void capitalize(char *str) {
    int capitalizeNext = 1;

    while (*str) {
        if (isalpha(*str)) {
            if (capitalizeNext) {
                *str = toupper((unsigned char)*str);
                capitalizeNext = 0;
            } else {
                *str = tolower((unsigned char)*str);
            }
        } else {
            capitalizeNext = 1;
        }

        str++;
    }
}

int main() {
    char example[] = "this is an example sentence.";
    printf("Original: %s\n", example);

    capitalize(example);

    printf("Capitalized: %s\n", example);

    return 0;
}
