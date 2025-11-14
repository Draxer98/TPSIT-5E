#include <stdio.h>      //std in-out
#include <stdlib.h>     //per utilizzo di certe funzioni:htonl,rand,....
#include <sys/socket.h> //funz. accept+bind+listen
#include <sys/types.h>  //funz. accept
#include <netinet/in.h> //definiscono la struttura degli indirizzi
#include <string.h>     //funz. stringhe
#include <errno.h>      //gestioni errori connessione
#include <ctype.h>      //bind
#include <unistd.h>     // file header che consente l'accesso alle API dello standard POSIX

#define Serverport 1450

int main()
{
    struct sockaddr_in servizio;
    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htonl(Serverport);

    char stringa[20];
    char risposta = "Messaggio ricevuto";
    int socketfd, soa, fromlen = sizeof(servizio);

    socketfd = socket(AF_INET, SOCK_STREAM, 0); // Creazione socket
    bind(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));
    listen(socketfd, 10);
    for (;;)
    {
        printf("Server in ascolto.........");
        fflush(stdout);
        soa = accept(socketfd, (struct sockaddr *)&servizio, &fromlen);
        //Legge dal client
        read(soa, stringa, sizeof(stringa));
        printf("Stringa ricevuta: %s\n", stringa);
        write(soa, risposta, sizeof(risposta));
        close(soa);
    }

    return 0;
}