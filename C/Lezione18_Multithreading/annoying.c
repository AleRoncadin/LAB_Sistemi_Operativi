#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>

/*
Questo codice crea un ciclo infinito che stampa "Hey apple!" ogni secondo. 
Se riceve un segnale SIGINT (CTRL + C) o SIGTERM, 
imposta una variabile globale signaled a 1 e stampa "You cannot terminate me!". 
Utilizza un mutex per sincronizzare l'accesso a questa variabile 
con i segnali e il ciclo principale.
*/

int signaled = 0; // Variabile globale per verificare se un segnale è stato ricevuto
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER; // Mutex per sincronizzazione

void handler(int x)
{
    pthread_mutex_lock(&m); // Acquisisce il mutex prima di modificare la variabile globale
    signaled = 1; // Imposta la variabile globale a 1 quando viene ricevuto un segnale
    pthread_mutex_unlock(&m); // Rilascia il mutex
}

int main()
{
    signal(SIGINT, handler); // Imposta la funzione 'handler' per il segnale SIGINT (CTRL + C)
    signal(SIGTERM, handler); // Imposta la funzione 'handler' per il segnale SIGTERM
    
    while (1)
    {
        pthread_mutex_lock(&m); // Acquisisce il mutex per controllare la variabile globale
        if (signaled)
            printf("You cannot terminate me!\n"); // Se un segnale è stato ricevuto, stampa il messaggio
        signaled = 0; // Resetta la variabile globale
        pthread_mutex_unlock(&m); // Rilascia il mutex
        printf("Hey apple!\n"); // Stampa il messaggio
        sleep(1); // Attende 1 secondo
    }
    return 0;
}
