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

#define SERVERPORT 6967

int main()
{
    struct sockaddr_in servizio;
    servizio.sin_family = AF_INET;
    servizio.sin_port = htons(SERVERPORT);

    char scelta[13] = "";
    char punteggio[100];

    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd < 0)
    {
        perror("Creazione della socket fallita");
        return -1;
    }

    if(inet_pton(AF_INET, "192.168.60.174", &servizio.sin_addr) <= 0)
    {
        perror("Errore conversione indirizzo IP");
        close(socketfd);
        return -1;
    }

    if (connect(socketfd, (struct sockaddr*)&servizio, sizeof(servizio)) < 0)
    {
        perror("Connessione col server fallita");
        close(socketfd);
        return -1;
    }

    while (1)
    {
        printf("Inserisci una fra le seguenti: \n");
        printf("FORBICE | SASSO | CARTA \n");
        printf("EXIT per terminare \n");
        fgets(scelta, sizeof(scelta), stdin);

        write(socketfd, scelta, strlen(scelta));
        read(socketfd, punteggio, sizeof(punteggio));
        printf("%s \n", punteggio);
        if (strcmp(scelta, "EXIT") == 0)
        {
            break;
        }
    }

    close(socketfd);

    return 0;
}