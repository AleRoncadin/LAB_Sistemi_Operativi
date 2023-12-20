#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/un.h>
#include <sys/types.h>
#include <sys/socket.h>

#include "common.h"
#include "freadline.h"

int main() {
    int sock = socket(AF_LOCAL, SOCK_STREAM, 0);
    check(sock, 1, "socket()");

    struct sockaddr_un server_addr = {
        .sun_family = AF_LOCAL,
        .sun_path = SOCKADDR
    };

    int connected = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    check(connected, 2, "connect()");

    printf("Connessione al server avvenuta.\n");

    // Ricevi e stampa il messaggio di benvenuto dal server
    int greetlen;
    recv(sock, &greetlen, sizeof(greetlen), 0);
    char greet[greetlen];
    recv(sock, greet, greetlen, 0);
    printf("Messaggio di benvenuto dal server:\n%s\n", greet);

    char line[256];
    printf("Inserisci una riga di testo (EOF per uscire):\n");

    while (fgets(line, sizeof(line), stdin) != NULL) {
        send(sock, line, strlen(line), 0);

        // Ricevi e stampa la risposta dal server
        int len = recv(sock, line, sizeof(line), 0);
        line[len] = '\0'; // Aggiungi terminatore nullo alla stringa
        printf("Risposta dal server:\n%s\n", line);

        printf("Inserisci una riga di testo (EOF per uscire):\n");
    }

    close(sock);
    printf("Connessione chiusa.\n");

    return 0;
}
