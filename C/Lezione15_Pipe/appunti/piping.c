#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MSGSIZE 14

int main() {
    int pipes[2] = { }; // Array per i descrittori di file della pipe

    if (pipe(pipes) == -1) { // Creazione della pipe e controllo degli errori
        perror("pipe call");
        return 1;
    }

    char msg[MSGSIZE] = { }; // Buffer per il messaggio

    pid_t pid = fork(); // Fork per creare un processo figlio

    switch (pid) {
        case -1:
            perror("fork call");
            return 2;
        case 0:
            // Codice eseguito dal processo figlio
            close(pipes[0]); // Chiude il lato di lettura della pipe

            // Scrive il messaggio nella pipe
            write(pipes[1], "Hello, world!", MSGSIZE);
            break;
        default:
            // Codice eseguito dal processo padre
            close(pipes[1]); // Chiude il lato di scrittura della pipe

            // Legge il messaggio dalla pipe
            read(pipes[0], msg, MSGSIZE);

            // Stampa il messaggio ricevuto
            printf("%s\n", msg);

            // Attendere che il processo figlio termini
            wait(NULL);
    }

    return 0;
}
