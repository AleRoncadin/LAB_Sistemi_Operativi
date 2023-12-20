#include <stdio.h>
#include <math.h>

// Struttura per rappresentare numeri complessi
struct complex
{
    float real;
    float imag;
};

float cabs(struct complex z);
float angle(struct complex z);
struct complex from_polar(float r, float theta);

// Funzione per calcolare il modulo di un numero complesso
float cabs(struct complex z)
{
    return sqrt(z.real * z.real + z.imag * z.imag);
}

// Funzione per calcolare l'argomento di un numero complesso in radianti
float angle(struct complex z)
{
    return atan2(z.imag, z.real);
}

// Funzione per creare un numero complesso a partire da modulo e argomento
struct complex from_polar(float r, float theta)
{
    struct complex result;
    result.real = r * cos(theta);
    result.imag = r * sin(theta);
    return result;
}

int main()
{
    // Esempio di utilizzo delle funzioni
    struct complex z1 = {3.0, 4.0};
    float mod_z1 = cabs(z1);
    float arg_z1 = angle(z1);

    printf("Modulo di z1: %f\n", mod_z1);
    printf("Argomento di z1: %f radians\n", arg_z1);

    // Creazione di un numero complesso da modulo e argomento
    struct complex z2 = from_polar(5.0, 0.8); // Raggio = 5.0, Angolo = 0.8 radianti

    printf("Parte reale di z2: %f\n", z2.real);
    printf("Parte immaginaria di z2: %f\n", z2.imag);

    return 0;
}
