/* Esercizio – Preparazione verifica
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
ciascuna città: Quante persone vi risiedono, L’età media dei residenti
*/

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
    printf("NOME: %s, COGNOME: %s, CITTA: %s, REDDITO: %.2lf, ETA: %d, CODICE FISCALE: %s\n",
           persona[i].nome, persona[i].cognome, persona[i].citta,
           persona[i].redditoAnnuo, persona[i].eta, persona[i].codiceFiscale);
}

// 1. Punto
void visualizzaConReddito(struct Persona persona[], int max, int min)
{
    printf("MAX\n");
    printf("NOME: %s, COGNOME: %s, CITTA: %s, REDDITO: %.2lf\n",
           persona[max].nome, persona[max].cognome, persona[max].citta, persona[max].redditoAnnuo);
    printf("MIN\n");
    printf("NOME: %s, COGNOME: %s, CITTA: %s, REDDITO: %.2lf\n",
           persona[min].nome, persona[min].cognome, persona[min].citta, persona[min].redditoAnnuo);
}

// 1. Punto
void visualizzazioneReddito(struct Persona persona[], int n)
{
    int max = 0, min = 0;

    for (int i = 1; i < n; i++)
    {
        if (persona[i].redditoAnnuo > persona[max].redditoAnnuo)
            max = i;
        if (persona[i].redditoAnnuo < persona[min].redditoAnnuo)
            min = i;
    }

    visualizzaConReddito(persona, max, min);
}

// 2. Punto
void bubbleSort(struct Persona persona[], int n)
{
    struct Persona temp;
    int i, j;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (persona[j].annoNascita > persona[j + 1].annoNascita)
            {
                temp = persona[j];
                persona[j] = persona[j + 1];
                persona[j + 1] = temp;
            }
        }
    }

    printf("\n--- Persone ordinate per anno di nascita ---\n");
    for (i = 0; i < n; i++)
        visualizza(persona, i);
}

// 3. Punto
int cercaPersonaCodiceFiscale(struct Persona persona[], char cercaCodiceFiscale[15], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(persona[i].codiceFiscale, cercaCodiceFiscale) == 0)
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

// 6. Punto
void visualizzaDataSup(struct Persona persona[], int cercaData, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (persona[i].annoNascita == cercaData)
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
        printf("\n%i° Persona\n", i + 1);
        printf("Inserisci il nome: ");
        scanf("%s", persona[i].nome);
        printf("Inserisci il cognome: ");
        scanf("%s", persona[i].cognome);
        printf("Inserisci l'eta: ");
        scanf("%d", &persona[i].eta);
        printf("Inserisci il codice fiscale: ");
        scanf("%s", persona[i].codiceFiscale);
        printf("Inserisci il reddito annuo: ");
        scanf("%lf", &persona[i].redditoAnnuo);
        printf("Inserisci l'anno di nascita: ");
        scanf("%d", &persona[i].annoNascita);
        printf("Inserisci la citta: ");
        scanf("%s", persona[i].citta);
    }

    // 1. Punto
    visualizzazioneReddito(persona, n);

    // 2. Punto
    bubbleSort(persona, n);

    // 3. Punto
    char cercaCodiceFiscale[15];
    printf("\nCerca Codice Fiscale: ");
    scanf("%s", cercaCodiceFiscale);

    int pos = cercaPersonaCodiceFiscale(persona, cercaCodiceFiscale, n);
    if (pos < 0)
    {
        printf("Non ci sono persone col codice fiscale cercato\n");
    }
    else
    {
        visualizza(persona, pos);
    }

    // 4. Punto
    double cercaReddito;
    printf("\nCerca reddito superiore o uguale a: ");
    scanf("%lf", &cercaReddito);
    visualizzaRedditoSuperiore(persona, cercaReddito, n);

    // 5. Punto
    double somma = 0, media = 0;
    for (int i = 0; i < n; i++)
    {
        somma += persona[i].redditoAnnuo;
    }
    media = somma / n;
    printf("\nMEDIA REDDITI REGISTRATI: %.2lf\n", media);

    // 6. Punto
    int cercaData;
    printf("\nInserisci l'anno di nascita da cercare: ");
    scanf("%d", &cercaData);
    visualizzaDataSup(persona, cercaData, n);

    return 0;
}
