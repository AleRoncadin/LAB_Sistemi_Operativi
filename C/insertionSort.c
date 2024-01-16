#include <stdio.h>

void ordina(int[]);

int main()
{
    int array[6] = {8, 64, 32, 87, 43, 76};
    ordina(array);
    printf("Array ordinato: \n");
    for(int i = 0; i < 6; i++)
    {
        printf("%d\n", array[i]);
    }
    return 0;
}

// Insertion Sort
void ordina(int array[])
{
    int value;
    int j;

    for(int i = 1; i < 6; i++)
    {
        value = array[i];
        j = i - 1;

        while(j >= 0 && array[j] > value)
        {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = value;
    }
}
