/*Esercizio – Preparazione verifica
Scrivere un programma in C che dopo aver dichiarato una struttura denominata Persona con i
seguenti campi: Nome, Cognome, età, codice fiscale, reddito annuo, anno_nascita,residenza(città) ;
determini:
1) La persona con reddito annuo più alto e quella con reddito annuo più basso.Visualizzare
per entrambe: nome, cognome, città e reddito.
2) Ordinare la lista delle persone in base all’anno di nascita** (dal più anziano al più
giovane), e visualizzarla.
3) Consentire all’utente di cercare una persona inserendo il codice fiscale..
4) Visualizzare tutte le persone con reddito superiore o uguale a un valore scelto dall’utente.
5) Calcolare la media dei redditi delle persone registrate nel sistema.
6) Visualizzare tutte le persone nate in un anno specifico, scelto dall’utente;
7) Visualizzare l'elenco delle persone raggruppate per città di residenza, indicando per
ciascuna città: Quante persone vi risiedono, L’età media dei residenti*/

#include <stdio.h>
#include <string.h>

struct Persona
{
    char nome[100];
    char cognome[100];
    int eta;
    char codiceFiscale[15];
    double redditoAnnuo;
    int annoNascita;
    char citta[100];
};

void visualizza(struct Persona persona[], int i)
{
    printf("NOME: %s, COGNOME: %s, CITTA: %s, REDDITO: %lf, ETA: %d, CODICE FISCALE: %s\n", persona[i].nome, persona[i].cognome, persona[i].citta, persona[i].redditoAnnuo, persona[i].eta, persona[i].codiceFiscale);
}

// 1. Punto
void visualizzaConReddito(struct Persona persona[], int max, int min)
{
    printf("MAX \n");
    printf("NOME: %s, COGNOME: %s, CITTA: %s, REDDITO: %lf\n", persona[max].nome, persona[max].cognome, persona[max].citta, persona[max].redditoAnnuo);
    printf("MIN \n");
    printf("NOME: %s, COGNOME: %s, CITTA: %s, REDDITO: %lf\n", persona[min].nome, persona[min].cognome, persona[min].citta, persona[min].redditoAnnuo);
}

// 1. Punto
void visualizzazioneReddito(struct Persona persona[], int n)
{
    double MaxReddito = 0;
    double MinReddito = 0;

    for (int i = 0; i < n - 1; i++)
    {
        if (persona[i + 1].redditoAnnuo > persona[i].redditoAnnuo)
        {
            MaxReddito = i + 1;
        }
        if (persona[i + 1].redditoAnnuo < persona[i].redditoAnnuo)
        {
            MaxReddito = i + 1;
        }
    }

    visualizzaConReddito(persona, MaxReddito, MinReddito);
}

// 3. Punto
int cercaPersonaCodiceFiscale(struct Persona persona[], char cercaCodiceFiscale[15], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (persona[i].codiceFiscale == cercaCodiceFiscale)
        {
            return i;
        }
    }

    return -1;
}

// 4. Punto
void visualizzaRedditoSuperiore(struct Persona persona[], double cercaReddito, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (persona[i].redditoAnnuo >= cercaReddito)
        {
            visualizza(persona, i);
        }
    }
}

int main()
{
    int n;

    printf("Quante persone vuoi inserire: ");
    scanf("%d", &n);

    struct Persona persona[n];

    for (int i = 0; i < n; i++)
    {
        printf("%i° Persona \n", i);
        printf("Inserisci il nome: ");
        scanf("%s", &persona[i].nome);
        printf("Inserisci il cognome: ");
        scanf("%s", &persona[i].cognome);
        printf("Inserisci l'eta: ");
        scanf("%d", &persona[i].eta);
        printf("Inserisci il codice fiscale: ");
        scanf("%s", &persona[i].codiceFiscale);
        printf("Inserisci il reddito annuo: ");
        scanf("%lf", &persona[i].redditoAnnuo);
        printf("Inserisci l'anno di nascita: ");
        scanf("%d", &persona[i].annoNascita);
        printf("Inserisci la città: ");
        scanf("%s", &persona[i].citta);
    }

    // 1. Punto
    visualizzazioneReddito(persona, n);

    // 3. Punto
    char cercaCodiceFiscale[15];

    printf("Cerca Codice Fiscale: ");
    scanf("%s", &cercaCodiceFiscale);

    if (cercaPersonaCodiceFiscale < 0)
    {
        printf("Non ci sono persone col codice fiscale cercato");
    }
    else
    {
        visualizza(persona, cercaPersonaCodiceFiscale(persona, cercaCodiceFiscale, n));
    }

    // 4. Punto
    double cercaReddita;

    printf("Cerca Reddito superiore: ");
    scanf("%s", &cercaReddita);

    visualizzaRedditoSuperiore(persona, cercaReddita, n);

    // 5. Punto
    double media;
    int somma;

    for (int i = 0; i < n; i++)
    {
        somma = somma + persona[i].redditoAnnuo;
    }

    media = somma / n;

    printf("MEDIA REDDITI REGISTRATI: %lf", media);

    return 0;
}
