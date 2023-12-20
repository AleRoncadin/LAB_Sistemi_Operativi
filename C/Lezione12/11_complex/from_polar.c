#include "complex.h"

// Funzione per creare un numero complesso a partire da modulo e argomento
struct complex from_polar(float r, float theta)
{
    struct complex result;
    result.real = r * cos(theta);
    result.imag = r * sin(theta);
    return result;
}