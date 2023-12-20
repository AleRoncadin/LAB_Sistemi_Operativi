#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

// Esempio: crea due thread che incrementano una variabile n 
// in modo sincronizzato utilizzando un mutex.

// Struttura per passare dati ai thread
struct arg_t
{
    int n;
    pthread_mutex_t mutex;
};

// Funzione eseguita dai thread
void *count(void *);

int main()
{
    // Inizializzazione della struttura dati con un contatore e un mutex
    struct arg_t arg = {0, PTHREAD_MUTEX_INITIALIZER};

    pthread_t th1, th2;
    
    // Creazione dei due thread e passaggio del riferimento alla struttura dati
    pthread_create(&th1, NULL, count, &arg);
    pthread_create(&th2, NULL, count, &arg);

    // Attende che entrambi i thread terminino
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);

    // Stampa il valore finale di n
    printf("n: %d\n", arg.n);

    return 0;
}

// Funzione per l'incremento sicuro di n
void *count(void *argptr)
{
    // Converte il puntatore generico alla struttura dati
    struct arg_t *arg = (struct arg_t *)argptr;

    int n = 0;

    // Ciclo per incrementare n in modo sincronizzato
    do
    {
        usleep(500000); // Attende per mezzo secondo
        pthread_mutex_lock(&arg->mutex); // Blocca il mutex
        arg->n += 1; // Incrementa n
        n = arg->n; // Copia n in una variabile locale
        pthread_mutex_unlock(&arg->mutex); // Sblocca il mutex
        printf("n: %d\n", n); // Stampa n
    } while (n < 42); // Continua fino a quando n è minore di 42

    return NULL; // Termina il thread
}
