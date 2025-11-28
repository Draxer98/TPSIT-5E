#include <stdio.h>      // std in-out
#include <stdlib.h>     // per utilizzo di certe funzioni:htonl,rand,....
#include <sys/socket.h> // funz. accept+bind+listen
#include <sys/types.h>  // funz. accept
#include <netinet/in.h> // definiscono la struttura degli indirizzi
#include <string.h>     // funz. stringhe
#include <errno.h>      // gestioni errori connessione
#include <ctype.h>      // bind
#include <unistd.h>     // file header che consente l'accesso alle API dello standard POSIX
#include <arpa/inet.h>

#define SERVERPORT 6967

int main(int argc, char *argv[]) {

    struct sockaddr_in dst;

    dst.sin_family = AF_INET;
    dst.sin_port = htons(SERVERPORT);
    dst.sin_addr.s_addr = htonl(INADDR_ANY);

    int socketfd, soa, dstlen = sizeof(dst);
    char client_message[13], message[13];

    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    bind(socketfd, (struct sockaddr*)&dst, sizeof(dst));
    listen(socketfd, 10);

    while(1) {
        printf("Server in ascolto ...\n");
        fflush(stdout);

        soa = accept(socketfd, (struct sockaddr*)&dst, &dstlen);

        read(soa, client_message, sizeof(client_message));

        if (strcmp("EXIT", client_message) == 0) {
            printf("Partita interrotta dal client.\n");
            close(soa);
        } else if (strcmp("CARTA", client_message)) {
            strcpy(message, "FORBICE\n");
        } else if (strcmp("SASSO", client_message)) {
            strcpy(message, "CARTE\n");
        } else if (strcmp("FORBICE", client_message)) {
            strcpy(message, "SASSO\n");
        }

        printf("Message from client: %s\n", client_message);
        close(soa);
    }

    close(socketfd);

    printf("\n\n");
    return 0;
}
