#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>

long int accumulatore = 0;
long int s; // valore di soglia
bool superato = false;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
long int id_superamento;

void *incrementaAccumulatore(void*);

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("Usage: %s n s\n", argv[0]);
        return 1;
    }

    unsigned int n = atoi(argv[1]);
    s = atoi(argv[2]);

    if (n < 1)
    {
        printf("n deve essere maggiore o uguale a 0\n");
        return 2;
    }

    // non posso fare pthread thread[n;
    pthread_t *thread = malloc(sizeof(pthread_t) * n);

    for(int i = 0; i < n; i++)
    {
        pthread_create(&thread[i], NULL, incrementaAccumulatore, NULL);
    }

    for(int i = 0; i < n; i++)
    {
        pthread_join(thread[i], NULL);
    }

    FILE *file = fopen("log.txt", "w");
    pthread_mutex_lock(&m); // blocca il mutex per stampare a video

    if(!file)
    {
        fprintf(stderr, "Errore nell'apertura del file");
        return 3; // termina il programma
    }
    else{
        fprintf(file, "Soglia superata dal thread con ID :%ld", id_superamento);
    }
    
    pthread_mutex_unlock(&m); // sblocca il mutex
    fclose(file);
    free(thread);

    return 0;
}

void *incrementaAccumulatore(void *arg)
{
    long int ID = pthread_self(); // id del thread

    srandom(time(NULL));
    long int numeroCasuale = random() % 6 + 1;

    pthread_mutex_lock(&m);
    while(!superato)
    {
        accumulatore += numeroCasuale;

        if(accumulatore > s)
        {
            id_superamento = ID;
            pthread_mutex_unlock(&m);
            return 0;
        }
        
        else
        {
            printf("Accumulatore: %ld, ID: %ld\n", accumulatore, ID);
        }

        pthread_mutex_unlock(&m);
        sleep(5);
    }
    
}