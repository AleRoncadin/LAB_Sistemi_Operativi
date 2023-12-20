#include "modifiche.h"

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("Uso: ./main file n_secondi");
        return 1;
    }

    int secondi = atoi(argv[2]);
    // controlla se la variabile contiene un valore intero sensato
    if (!secondi)
    {
        printf("Il tempo in secondi deve essere intero positivo\n");
        return 2;
    }

    contaModifiche(argv[1], secondi);

    return 0;
}