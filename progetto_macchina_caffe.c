#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Costanti
#define MAX_CIALDE 5
#define ACQUA_INIZIALE 1000

// Variabili globali
int caldaia_calda = 0;
int acqua = ACQUA_INIZIALE;
int cialde_usate = 0;

// Funzione per attendere
void attendi(int secondi) {
    time_t start = time(NULL);
    while (time(NULL) - start < secondi) {
        // Aspetta
    }
}

// Funzione per riscaldare la caldaia
void riscalda_caldaia() {
    printf("Riscaldamento caldaia...\n");
    attendi(2);
    caldaia_calda = 1;
    printf("Caldaia pronta!\n\n");
}

// Funzione per mostrare il menu
void mostra_menu() {
    printf("Scegli una bevanda:\n");
    printf("1. Espresso (30 ml)\n");
    printf("2. Lungo (60 ml)\n");
    printf("3. Cappuccino (120 ml)\n");
    printf("0. Esci\n");
}

// Funzione per preparare la bevanda
void prepara_bevanda(char nome[], int ml) {
    if (!caldaia_calda) {
        printf("Caldaia non è calda!\n\n");
        return;
    }

    if (acqua < ml) {
        printf("Acqua insufficiente! (%d ml rimasti)\n\n", acqua);
        return;
    }

    if (cialde_usate >= MAX_CIALDE) {
        printf("Il serbatoio delle cialde è pieno! Svuotalo prima.\n\n");
        return;
    }

    printf("Preparazione di %s (%d ml)...\n", nome, ml);
    int tempo = ml / 5; // 5 ml al secondo
    for (int i = 0; i < tempo; i++) {
        printf(".");
        fflush(stdout);
        attendi(1);
    }
    printf("\nBevanda pronta!\n\n");

    acqua -= ml;
    cialde_usate++;
    printf("Acqua rimasta: %d ml\n", acqua);
    printf("Cialde usate: %d/%d\n\n", cialde_usate, MAX_CIALDE);
}

// Funzione per svuotare serbatoio
void svuota_serbatoio() {
    printf("Svuotamento serbatoio cialde...\n");
    attendi(1);
    cialde_usate = 0;
    printf("Serbatoio svuotato!\n\n");
}

// MAIN
int main() {
    int scelta;
    printf("Accensione macchina...\n");
    attendi(1);
    riscalda_caldaia();

    while (1) {
        mostra_menu();
        printf("Scelta: ");
        scanf("%d", &scelta);

        if (scelta == 0) {
            printf("Chiusura macchina...\n");
            break;
        }

        if (cialde_usate >= MAX_CIALDE) {
            printf("Il serbatoio è pieno. Vuoi svuotarlo? (1 = sì, 0 = no): ");
            int risp;
            scanf("%d", &risp);
            if (risp == 1) {
                svuota_serbatoio();
            } else {
                printf("Operazione annullata.\n\n");
                continue;
            }
        }

        switch (scelta) {
            case 1:
                prepara_bevanda("Espresso", 30);
                break;
            case 2:
                prepara_bevanda("Lungo", 60);
                break;
            case 3:
                prepara_bevanda("Cappuccino", 120);
                break;
            default:
                printf("Scelta non valida!\n\n");
        }
    }

    return 0;
}

