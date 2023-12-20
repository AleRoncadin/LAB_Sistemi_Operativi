#include "complex.h"

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