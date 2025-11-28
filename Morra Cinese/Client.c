#include <stdio.h>      //std in-out
#include <stdlib.h>     //per utilizzo di certe funzioni:htonl,rand,....
#include <sys/socket.h> //funz. accept+bind+listen
#include <sys/types.h>  //funz. accept
#include <netinet/in.h> //definiscono la struttura degli indirizzi
#include <string.h>     //funz. stringhe
#include <errno.h>      //gestioni errori connessione
#include <ctype.h>      //bind
#include <unistd.h>     // file header che consente l'accesso alle API dello standard POSIX

#define SERVERPORT 1450

int main()
{
    struct sockaddr_in servizio;
    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htonl(SERVERPORT);

    char scelta[13];
    char punteggio[100];

    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd < 0)
    {
        return -1;
    }

    
    if (connect(socketfd, (struct sockaddr_in *)&servizio, sizeof(servizio)) < 0)
    {
        return -1;
    }

    printf("Inserisci una fra le seguenti: \n");
    printf("FORBICE | SASSO | CARTA \n");
    scanf("%s", scelta);

    write(socketfd, scelta, strlen(scelta));
    read(socketfd, punteggio, strlen(punteggio));
    printf("%s", punteggio);

    close(socketfd);

    return 0;
}