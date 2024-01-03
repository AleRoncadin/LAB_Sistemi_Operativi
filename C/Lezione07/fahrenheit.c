#include <stdio.h> // Funzioni di I/O dalla libreria standard

int main()
{
    float fahr = 0; // dichiarazione di una variabile di tipo float
    printf("Tabella Fahrenheit-Celsius:\n");

    while(fahr <= 300) // ciclo while
    {
        float celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f °F -> %6.1f °C\n", fahr, celsius);
        fahr = fahr + 20;
    }
    return 0;
}