#ifndef _COMPLEX_H__

#define _COMPLEX_H__

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Struttura per rappresentare numeri complessi
struct complex
{
    float real;
    float imag;
};

float cabs(struct complex z);
float angle(struct complex z);
struct complex from_polar(float r, float theta);

#endif