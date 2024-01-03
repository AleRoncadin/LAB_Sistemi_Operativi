/*
Esame 30 Gennaio 2015

Sia data la seguente struttura ricorsiva in C:
struct elemento {
int valore;
struct elemento *prossimo;
};
struct elemento *lista=NULL;
Si scriva il codice per aggiungere alla lista dinamica vuota puntata da lista gli elementi 2, 12, 6
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    // Definizione di una struttura elemento che rappresenta un nodo della lista
    struct elemento
    {
        int valore;                 // Campo per l'intero valore
        struct elemento *prossimo;  // Puntatore al prossimo elemento nella lista
    };

    // Inizializzazione di un puntatore a un elemento che rappresenta la lista
    struct elemento *lista = NULL;

    // Allocazione di memoria per il primo elemento della lista
    lista = malloc(sizeof(struct elemento));

    if (lista == NULL)  // Controllo se l'allocazione di memoria è fallita
    {
        perror("Allocazione di memoria fallita!\n");  // Stampa un errore su stderr
        exit(1);  // Esce dal programma con codice di errore
    }
    // Assegnazione di un valore al primo elemento
    lista->valore = 2;
    printf("%d\n", lista->valore);

    // Allocazione di memoria per il secondo elemento della lista
    lista->prossimo = malloc(sizeof(struct elemento));
    if (lista->prossimo == NULL)  // Controllo se l'allocazione di memoria è fallita
    {
        perror("Allocazione di memoria fallita!\n");  // Stampa un errore su stderr
        exit(1);  // Esce dal programma con codice di errore
    }

    // Assegnazione di un valore al secondo elemento
    lista->prossimo->valore = 12;
    printf("%d\n", lista->prossimo->valore);

    // Allocazione di memoria per il terzo elemento della lista
    lista->prossimo->prossimo = malloc(sizeof(struct elemento));
    if (lista->prossimo->prossimo == NULL)  // Controllo se l'allocazione di memoria è fallita
    {
        perror("Allocazione di memoria fallita!\n");  // Stampa un errore su stderr
        exit(1);  // Esce dal programma con codice di errore
    }

    // Assegnazione di un valore al terzo elemento
    lista->prossimo->prossimo->valore = 6;
    printf("%d\n", lista->prossimo->prossimo->valore);

    // Imposta il puntatore del terzo elemento a NULL, indicando la fine della lista
    lista->prossimo->prossimo->prossimo = NULL;
    
    return 0;
}
