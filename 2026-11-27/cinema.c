# include <stdio.h>
# include <string.h>

# define NUMERO_SALE 5
# define CAPACITA_SALA 100
# define COSTO_BIGLIETTO 5

typedef struct Film {
    char titolo[128];
    char genere[16];
    int durata; // in minuti
} TFilm;

typedef struct Sala {
    TFilm film;
    int posti_liberi;
} TSala;

int main() {
    TSala cinema[NUMERO_SALE];
    int scelta, sala, biglietti, durata_massima, spettatori_totali = 0;
    char titolo[128];
    char genere[16];
    int ch;

    do {
        printf("*** M E N U ***\n"
               "1. Inserimento film nelle sale\n"
               "2. Vendita biglietto\n"
               "3. Visualizza posti liberi per sala\n"
               "4. Visualizza film per genere\n"
               "5. Visualizza film di una certa durata massima\n"
               "6. Visualizza il guadagno attuale\n"
               "...\n"
               "0. Esci\n"
               "Scegli: ");
        scanf("%d", &scelta);
        while ((ch = fgetc(stdin)) != EOF && ch != '\n') {}

        switch (scelta) {
            case 1:
                //Inserimento film nelle sale
                for (int i=0; i<NUMERO_SALE; i++) {
                    printf("*** SALA %d\n", i+1);
                    printf("Titolo del film: ");
                    fgets(cinema[i].film.titolo, 128, stdin );
                    printf("Genere e durata (min) del film: ");
                    scanf("%s%d", cinema[i].film.genere, &cinema[i].film.durata);
                    while ((ch = fgetc(stdin)) != EOF && ch != '\n') {}
                    cinema[i].posti_liberi = CAPACITA_SALA;
                }
                break;
            case 2:
                // Vendita biglietto
                printf("Quale film vuoi vedere? ");
                fgets(titolo, 128, stdin );

                // Verifico che quel film sia in proiezione
                sala = -1;
                for (int i=0; i<NUMERO_SALE; i++) {
                    if (strcmp(titolo, cinema[i].film.titolo) == 0) {
                        sala = i;
                        break;
                    }
                }

                if (sala == -1) {
                    printf("Il film che cerchi non è in proiezione.\n");
                } else {
                    // Verifico la disponibilità di posti
                    printf("Il film è proiettato in sala %d, con %d posti liberi, "
                           "durata: %d minuti\n", sala+1, cinema[sala].posti_liberi, cinema[sala].film.durata);
                    printf("Quanti biglietti vuoi acquistare? ");
                    scanf("%d", &biglietti);
                    if (cinema[sala].posti_liberi >= biglietti) {
                        cinema[sala].posti_liberi -= biglietti;
                        printf("Acquisto effettuato.\n");
                    } else {
                        printf("Mi dispiace ma non ci sono abbastanza posti liberi.\n");
                    }
                }
                break;
            case 3:
                // Visualizza posti liberi per sala
                for (int i=0; i < NUMERO_SALE; i++) {
                    printf("Sala %d, posti liberi: %d\n",
                        i+1, cinema[i].posti_liberi);
                }
                break;
            case 4:
                // Visualizzazione per genere
                printf("Che genere ti interessa? ");
                scanf("%s", genere);
                for (int i=0; i < NUMERO_SALE; i++) {
                    if (strcmp(genere, cinema[i].film.genere) == 0) {
                        printf("%s    Sala %d, posti liberi %d\n",
                            cinema[i].film.titolo, i+1, cinema[i].posti_liberi);
                    }
                }
                break;
            case 5:
                // Visualizza film di una certa durata massima
                printf("Inserisci durata massima (min): ");
                scanf("%d", &durata_massima);
                for (int i=0; i < NUMERO_SALE; i++) {
                    if (cinema[i].film.durata <= durata_massima) {
                        printf("%s    Sala %d, posti liberi %d, durata %d min\n",
                            cinema[i].film.titolo, i+1, cinema[i].posti_liberi, cinema[i].film.durata);
                    }
                }
                break;
            case 6:
                // Calcolo guadagno
                for (int i=0; i < NUMERO_SALE; i++) {
                    spettatori_totali += (CAPACITA_SALA - cinema[i].posti_liberi);
                }
                printf("Il guadagno attuale è di %d euro\n", spettatori_totali * COSTO_BIGLIETTO);

            case 0:
                // Esci
                break;
        }
    } while (scelta != 0);
    return 0;
}