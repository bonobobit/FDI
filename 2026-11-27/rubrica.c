# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define NUMERO_CONTATTI 10
# define DIM_NOME 30
# define DIM_COGNOME 30
# define DIM_NUMERO 11

typedef struct Contatto {
    char nome[DIM_NOME];
    char cognome[DIM_COGNOME];
    char numero[DIM_NUMERO];
} TContatto;

int main() {
    TContatto rubrica[NUMERO_CONTATTI]= {0};
    int scelta = -1;
    int posizione = 1;
    do {
        printf("*** MENU ***\n"
            "1. Visualizza contatti\n"
            "2. Aggiungi nuovo contatto\n"
            "3. Rimuovi contatto\n"
            //4. Ricerca
            "0. Esci\n"
            ">>");
        scanf("%d", &scelta);
        switch (scelta) {
            case 1:
                // Visualizza contatti
                for (int i=0; i<NUMERO_CONTATTI; i++) {
                    printf("%d."
                        "Nome: %40s | "
                        "Cognome: %40s | "
                        "Numero: %20s\n",
                        i+1, rubrica[i].nome, rubrica[i].cognome, rubrica[i].numero);
                }
                break;
            case 2:
                for (int i=0; i<NUMERO_CONTATTI; i++) {
                    if (rubrica[i].nome[0] == '\0') {
                        printf("Nome nuovo contatto: ");
                        scanf("%s", rubrica[i].nome);
                        printf("Cognome nuovo contatto: ");
                        scanf("%s", rubrica[i].cognome);
                        printf("Numero nuovo contatto: ");
                        scanf("%s", &rubrica[i].numero);
                        break;
                    } else {
                        printf("Rubrica piena\n");
                    }
                }

                break;
            case 3:
                printf("Seleziona posizione in rubrica del contatto da eliminare.\n"
                       ">>");
                scanf("%d", &posizione);
                strcpy(rubrica[posizione-1].nome, "");
                strcpy(rubrica[posizione-1].cognome, "");
                strcpy(rubrica[posizione-1].numero, "");
                break;
            case 0:
                break;
        }

    } while (scelta != 0);
}