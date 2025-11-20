#include <stdio.h>      //std in-out
#include <stdlib.h>     //per utilizzo di certe funzioni:htonl,rand,....
#include <sys/socket.h> //funz. accept+bind+listen
#include <sys/types.h>  //funz. accept
#include <netinet/in.h> //definiscono la struttura degli indirizzi
#include <string.h>     //funz. stringhe
#include <errno.h>      //gestioni errori connessione
#include <ctype.h>      //bind
#include <unistd.h>     //ile header che consente l'accesso alle API dello standard POSIX

#define Serverport 6969

int main()
{
    int cont = 0;
    struct sockaddr_in servizio;
    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(Serverport);

    int taxi[10] = {
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
    };
    char stringa[20];
    char inizioTaxi[20] = "Taxi acquistato";
    char fineTaxi[30] = "Servizio terminato!";
    int socketfd, soa, fromlen = sizeof(servizio);

    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    bind(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));
    listen(socketfd, 10);

    for (;;)
    {
        printf("Server in ascolto.... \n");
        fflush(stdout);
        soa = accept(socketfd, (struct sockaddr *)&servizio, &fromlen);

        if (cont == 10)
        {
            write(soa, fineTaxi, sizeof(fineTaxi));
        }
        else
        {
            int n = read(soa, stringa, sizeof(stringa) - 1);
            if (n > 0)
            {
                stringa[n] = '\0';
                printf("Richiesta: %s\n", stringa);
            }
            for (int i = 0; i < sizeof(taxi) / sizeof(taxi[0]); i++)
            {
                if (cont == sizeof(taxi) / sizeof(taxi[0]))
                {
                    write(soa, fineTaxi, sizeof(fineTaxi));
                }
                else if (taxi[i] == 0)
                {
                    taxi[i] = 1;

                    write(soa, inizioTaxi, strlen(inizioTaxi));
                    break;
                }

                cont++;
            }
        }

        close(soa);
    }
}