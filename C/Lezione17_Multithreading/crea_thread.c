#include <stdio.h> // Includi la libreria standard di input/output
#include <pthread.h> // Includi la libreria per la gestione dei thread

// Dichiarazione della funzione print_msg
void *print_msg(void *ptr);

int main() // Funzione principale
{
    char msg1[] = "Thread 1"; // Messaggio per il primo thread
    char msg2[] = "Thread 2"; // Messaggio per il secondo thread

    pthread_t thread1, thread2; // Dichiarazione dei thread

    // Creazione del primo thread che eseguirà la funzione print_msg con argomento msg1
    pthread_create(&thread1, NULL, print_msg, (void *)msg1);

    // Creazione del secondo thread che eseguirà la funzione print_msg con argomento msg2
    pthread_create(&thread2 ,NULL, print_msg, (void *)msg2);

    // Attesa che il primo thread termini
    pthread_join(thread1, NULL);

    // Attesa che il secondo thread termini
    pthread_join(thread2, NULL);

    return 0; // Fine del programma
}

// Funzione eseguita dai thread
void *print_msg(void *ptr)
{
    char *arg = (char *) ptr; // Conversione dell'argomento in stringa

    while(1) // Ciclo infinito
        printf("%s\n", arg); // Stampa del messaggio

    return NULL; // Fine della funzione
}
