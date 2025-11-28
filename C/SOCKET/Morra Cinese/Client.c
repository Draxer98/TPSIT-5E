#include <stdio.h>      //std in-out
#include <stdlib.h>     //per utilizzo di certe funzioni:htonl,rand,....
#include <sys/socket.h> //funz. accept+bind+listen
#include <sys/types.h>  //funz. accept
#include <netinet/in.h> //definiscono la struttura degli indirizzi
#include <string.h>     //funz. stringhe
#include <errno.h>      //gestioni errori connessione
#include <ctype.h>      //bind
#include <unistd.h>     // file header che consente l'accesso alle API dello standard POSIX
#include <arpa/inet.h>  

#define SERVERPORT 1450

int main()
{
    struct sockaddr_in servizio;
    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    servizio.sin_port = htonl(SERVERPORT);

    char scelta[13] = "";
    char punteggio[100];

    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd < 0)
    {
        perror("Creazione della socket fallita");
        return -1;
    }

    if(inet_pton(AF_INET, "26.249.73.119", &servizio.sin_addr) <= 0)
    {
        perror("Errore conversione indirizzo IP");
        close(socketfd);
        return -1;
    }

    if (connect(socketfd, (struct sockaddr*)&servizio, sizeof(servizio)) < 0)
    {
        perror("Connessione col server fallita");
        return -1;
    }

    while (1)
    {
        printf("Inserisci una fra le seguenti: \n");
        printf("FORBICE | SASSO | CARTA \n");
        printf("FINE per terminare");
        fgets(scelta, sizeof(scelta), stdin);

        write(socketfd, scelta, strlen(scelta));
        read(socketfd, punteggio, strlen(punteggio));
        printf("%s", punteggio);
        if (strcmp(scelta, "FINE") == 0)
        {
            break;
        }
    }

    close(socketfd);

    return 0;
}