#include "complex.h"

// Funzione per calcolare l'argomento di un numero complesso in radianti
float angle(struct complex z)
{
    return atan2(z.imag, z.real);
}