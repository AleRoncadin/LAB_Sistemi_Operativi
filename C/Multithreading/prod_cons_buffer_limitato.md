```c

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define LENGTH 10
#define MAX 100

int buffer[LENGTH]; // buffer condiviso di lunghezza LENGTH
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // mutex per l'accesso esclusivo
pthread_cond_t not_empty_buffer = PTHREAD_COND_INITIALIZER; // condition variable: buffer non vuoto
pthread_cond_t not_full_buffer = PTHREAD_COND_INITIALIZER; // condition variable: buffer non pieno

int full() {
    for (int i = 0; i < LENGTH; i++) {
        if (buffer[i] == -1) {
            return 0; // Buffer non è pieno
        }
    }
    return 1; // Buffer pieno
}

int empty() {
    for (int i = 0; i < LENGTH; i++) {
        if (buffer[i] != -1) {
            return 0; // Buffer non è vuoto
        }
    }
    return 1; // Buffer vuoto
}

void *producer(void *n) {
    int elemento, i;
    while (1) {
        pthread_mutex_lock(&mutex); // Inizio sezione critica
        while (full()) pthread_cond_wait(&not_full_buffer, &mutex); // Controllo se posso inserire un nuovo elemento
        for (i = 0; i < LENGTH; i++) {
            if (buffer[i] == -1) {
                elemento = rand() % MAX + 1; // Genero l'elemento
                buffer[i] = elemento; // Inserisco l'elemento
                break;
            }
        }
        pthread_cond_signal(&not_empty_buffer); // Segnalo che il buffer non è vuoto
        pthread_mutex_unlock(&mutex); // Fine sezione critica
    }
}

void *consumer(void *n) {
    int elemento, i;
    while (1) {
        pthread_mutex_lock(&mutex); // Inizio sezione critica
        while (empty()) pthread_cond_wait(&not_empty_buffer, &mutex); // Controllo se posso prelevare un elemento
        for (i = 0; i < LENGTH; i++) {
            if (buffer[i] != -1) {
                elemento = buffer[i]; // Prelevo l'elemento
                buffer[i] = -1; // Indico che la posizione è libera
                break;
            }
        }
        pthread_cond_signal(&not_full_buffer); // Segnalo che il buffer non è pieno
        pthread_mutex_unlock(&mutex); // Fine sezione critica
    }
}

```