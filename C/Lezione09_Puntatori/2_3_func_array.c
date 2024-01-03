#include <stdio.h>
#define SIZE 6

void creaArray(int *);
void stampaArray(int *);
void reverse(int *);
void sort(int *);
void quickSort(int *, int, int);
void swap(int *, int *);
int partition(int *, int, int);

int main()
{
    int array[SIZE];
    creaArray(array);
    reverse(array);
    sort(array);
    quickSort(array, 0, SIZE - 1);
    printf("\n------QuickSort------\n");
    stampaArray(array);

    return 0;
}

void creaArray(int *array)
{
    printf("------INSERISCI GLI ELEMENTI------\n");
    for (int *p = array; p < array + SIZE; p++)
    {
        int i = p - array + 1;
        printf("Elemento %d: ", i);
        scanf("%d", p);
    }
}

void stampaArray(int *array)
{
    for (int *p = array; p < array + SIZE; p++)
    {
        printf("%d\n", *p);
    }
}

void reverse(int *array)
{
    int temp[SIZE]; // array usiliario
    int i;

    // salva nell'array usiliario l'array in ordine inverso
    for (int *p = array; p < array + SIZE; p++)
    {
        i = SIZE - 1 - (p - array);
        temp[i] = *p;
    }

    // copia gli elementi in ordine inverso nell'array iniziale
    for (int *p = array; p < array + SIZE; p++)
    {
        i = p - array;
        *p = temp[i];
    }

    // stampa tutti gli elementi dell'array iniziale (ora in ordine inverso)
    printf("\n------Reverse------\n");
    stampaArray(array);
}

void sort(int *array)
{
    int value;
    int j;

    for (int *p = array + 1; p < array + SIZE; p++)
    {
        value = *p;
        j = (p - array) - 1;

        while (j >= 0 && array[j] > value)
        {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = value;
    }

    printf("\n------Sort------\n");
    stampaArray(array);
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high)
{
    // choose the pivot

    int pivot = arr[high];
    // Index of smaller element and Indicate
    // the right position of pivot found so far
    int i = (low - 1);

    for (int j = low; j <= high; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            // Increment index of smaller element
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// The Quicksort function Implement

void quickSort(int *arr, int low, int high)
{
    // when low is less than high
    if (low < high)
    {
        // pi is the partition return index of pivot

        int pi = partition(arr, low, high);

        // Recursion Call
        // smaller element than pivot goes left and
        // higher element goes right
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
