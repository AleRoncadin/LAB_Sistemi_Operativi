#include <stdio.h>
#include <math.h> // Aggiunto l'header per sqrt
#include <stdlib.h>

struct point
{
    float x;
    float y;
};

float abs_point(struct point p);

float abs_point(struct point p)
{
    return sqrt(p.x * p.x + p.y * p.y);
}

int main()
{
    struct point p = {3, 4};
    printf("p contiene %f, %f\n", p.x, p.y);

    struct point p2 = {};
    printf("Inserisci i numeri di p2 { %f, %f }: ", p2.x, p2.y);
    scanf("{ %f , %f }", &p2.x, &p2.y);
    printf("%f, %f\n", p2.x, p2.y);

    printf("abs di p: %f\n", abs_point(p));

    struct point points[] = {
        {3, 4},
        {12, 15},
        {0, -1}
    };

    printf("Array di struct: \n");
    for (int i = 0; i < sizeof(points) / sizeof(points[0]); ++i) 
        printf("%f %f\n", points[i].x, points[i].y);

    struct point *pp = &p;
    printf("%f %f\n", pp->x, pp->y); // Equivalente alla seguente
    printf("%f %f\n", (*pp).x, (*pp).y);

    return 0;
}
