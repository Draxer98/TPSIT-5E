/*Scrivere un programma in C che dopo aver inserito una stringa a piacere determini e o verifichi:
1) Che contenga solo lettere;
2) Il conteggio di una lettera (se presente) scelta dall’utente;
3) Crei 2 ulteriori stringhe che contengano 1 le lettere di posizione pari; la 2° le lettere di posizione
dispari;
4) Verifichi se contiene doppie.
Inserita una 2° stringa determinare:
1) Quale delle 2 è più lunga e più corta;
2) Quali sono le lettere contenute in ambedue le stringhe;
3) Quale delle 2 stringhe contiene più vocali;
4) Quale delle 2 stringhe contiene più consonanti;*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str1[100], str2[100];
    int i;

    // Inserimento della prima stringa
    printf("Inserisci la prima stringa: ");
    scanf("%s", str1);

    // 1. Verifica se contiene solo lettere
    int soloLettere = 1;
    for (i = 0; str1[i] != '\0'; i++)
    {
        if (!((str1[i] >= 'a' && str1[i] <= 'z') || (str1[i] >= 'A' && str1[i] <= 'Z')))
        {
            soloLettere = 0;
            break;
        }
    }
    if (soloLettere)
    {
        printf("La stringa contiene solo lettere.\n");
    }
    else
    {
        printf("La stringa NON contiene solo lettere.\n");
    }

    // 2. Conteggio di una lettera scelta dall’utente
    char lettera;
    int contatore = 0;
    printf("Inserisci una lettera da contare nella stringa: ");
    scanf(" %c", &lettera);

    for (i = 0; str1[i] != '\0'; i++)
    {
        if (str1[i] == lettera)
        {
            contatore++;
        }
    }
    printf("La lettera '%c' appare %d volte.\n", lettera, contatore);

    // 3. Creazione stringhe di posizione pari e dispari
    char pari[100], dispari[100];
    int p = 0, d = 0;
    for (i = 0; str1[i] != '\0'; i++)
    {
        if (i % 2 == 0)
        {
            pari[p++] = str1[i];
        }
        else
        {
            dispari[d++] = str1[i];
        }
    }
    pari[p] = '\0';
    dispari[d] = '\0';

    printf("Lettere in posizione pari: %s\n", pari);
    printf("Lettere in posizione dispari: %s\n", dispari);

    // 4. Verifica se contiene doppie
    int doppie = 0;
    for (i = 0; str1[i + 1] != '\0'; i++)
    {
        if (str1[i] == str1[i + 1])
        {
            doppie = 1;
            break;
        }
    }
    if (doppie)
    {
        printf("La stringa contiene doppie.\n");
    }
    else
    {
        printf("La stringa NON contiene doppie.\n");
    }

    // Inserimento della seconda stringa
    printf("\nInserisci la seconda stringa: ");
    scanf("%s", str2);

    // 5. Quale è più lunga/più corta
    int len1 = 0, len2 = 0;
    while (str1[len1] != '\0')
        len1++;
    while (str2[len2] != '\0')
        len2++;

    if (len1 > len2)
    {
        printf("La prima stringa è più lunga.\n");
    }
    else if (len2 > len1)
    {
        printf("La seconda stringa è più lunga.\n");
    }
    else
    {
        printf("Le due stringhe hanno la stessa lunghezza.\n");
    }

    // 6. Lettere comuni nelle due stringhe
    printf("Lettere comuni: ");
    for (i = 0; str1[i] != '\0'; i++)
    {
        char c1 = str1[i];
        int trovato = 0;
        // Verifica se già stampata
        for (int k = 0; k < i; k++)
        {
            if (str1[k] == c1)
            {
                trovato = 1;
                break;
            }
        }
        if (trovato)
            continue;

        for (int j = 0; str2[j] != '\0'; j++)
        {
            if (c1 == str2[j])
            {
                printf("%c ", c1);
                break;
            }
        }
    }
    printf("\n");

    // 7. Stringa con più vocali
    int vocali1 = 0, vocali2 = 0;
    for (i = 0; str1[i] != '\0'; i++)
    {
        char c = str1[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        {
            vocali1++;
        }
    }
    for (i = 0; str2[i] != '\0'; i++)
    {
        char c = str2[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        {
            vocali2++;
        }
    }

    if (vocali1 > vocali2)
    {
        printf("La prima stringa ha più vocali.\n");
    }
    else if (vocali2 > vocali1)
    {
        printf("La seconda stringa ha più vocali.\n");
    }
    else
    {
        printf("Le due stringhe hanno lo stesso numero di vocali.\n");
    }

    // 8. Stringa con più consonanti
    int consonanti1 = 0, consonanti2 = 0;
    for (i = 0; str1[i] != '\0'; i++)
    {
        char c = str1[i];
        if (((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) &&
            !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
              c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'))
        {
            consonanti1++;
        }
    }
    for (i = 0; str2[i] != '\0'; i++)
    {
        char c = str2[i];
        if (((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) &&
            !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
              c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'))
        {
            consonanti2++;
        }
    }

    if (consonanti1 > consonanti2)
    {
        printf("La prima stringa ha più consonanti.\n");
    }
    else if (consonanti2 > consonanti1)
    {
        printf("La seconda stringa ha più consonanti.\n");
    }
    else
    {
        printf("Le due stringhe hanno lo stesso numero di consonanti.\n");
    }

    return 0;
}
