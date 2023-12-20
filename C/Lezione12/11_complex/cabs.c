#include "complex.h"

// Funzione per calcolare il modulo di un numero complesso
float cabs(struct complex z)
{
    return sqrt(z.real * z.real + z.imag * z.imag);
}