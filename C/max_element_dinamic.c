#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, num;
    float *data;

    printf("Enter total number of elements (1 to 100):");
    scanf("%d", &num);

    // con (float *) fa il casting da (void *)
    data = (float *)calloc(num, sizeof(float));
    if (data == NULL)
    {
        printf(" Error !!! memory not allocated . ");
        exit(1);
    }
    printf("\n");
    
    for (i = 0; i < num; ++i)
    {
        printf("\nEnter Element Number %d: ", i + 1);
        scanf("%f", data + i);
    }
    
    for (i = 1; i < num; ++i)
    {
        // Change < to > if you want to find the smallest number
        if (*data < *(data + i))
        {
            *data = *(data + i);
        }
    }
    printf("Largest element = %.2f", *data);

    return 0;
}