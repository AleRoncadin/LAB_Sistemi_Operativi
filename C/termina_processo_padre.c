/*
Esame 30 Gennaio 2015

Si scriva un programma C che crei un processo figlio e si metta in attesa della terminazione
di quest’ultimo. Il figlio tuttavia decide di terminare il processo padre inviandogli il segnale SIGKILL.
Suggerimento: per ottenere il PID del padre si utilizzi la seguente system call:
SYNOPSIS
#include <sys/types.h>
#include <unistd.h>
pid_t getppid(void);
DESCRIPTION: getppid() returns the process ID of the parent of the calling process.

*/

// GUARDARE LEZIONE 14!!!

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork(); // Creazione di un nuovo processo figlio

    switch (pid)
    {
    case -1: // Se la creazione del processo fallisce
        perror("Fork failed!\n"); // Stampa un errore
        exit(1); // Esce con codice di errore

    case 0: // Codice eseguito dal processo figlio
        printf("I am the son.\n"); // Stampa un messaggio
        pid_t ppid = getppid(); // Ottiene il PID del padre
        printf("Killing father (PID: %d)!\n", ppid); // Stampa il messaggio di uccisione del padre
        // kill(ppid, SIGKILL); // Invia un segnale di terminazione al padre
        printf("Exiting (escaping :)\n"); // Stampa un messaggio di uscita
        break; // Esce dallo switch

    default: // Codice eseguito dal processo padre
        printf("I am the father.\n"); // Stampa un messaggio
        waitpid(pid, NULL, 0); // Il padre attende la terminazione del figlio
        printf("Son terminated!\n"); // Stampa un messaggio di terminazione del figlio
    }

    return 0; // Termina il programma
}
