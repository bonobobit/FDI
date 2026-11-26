# include <stdio.h>

int main() {
    int min = 0, max = 0;
    printf("Inserisci intervallo di ricerca (es. 10 20): ");
    scanf(" %d %d", &min, &max);

    char conferma = 'n';
    int risposta;
    int tentativi = 0;

    while (1) {
        risposta = (min + max) / 2;
        printf("Hai pensato %d (s/n)? ", risposta);
        tentativi++;
        scanf(" %c", &conferma);
        if (conferma == 's') {
            printf("EVVIVA! Ho indovinato in %d tentativi", tentativi);
            return 0;
        } else if (conferma == 'n') {
            printf("Il numero che hai pensato è maggiore (>) o minore (<) di %d? ", risposta);
            scanf(" %c", &conferma);
            if (conferma == '<') {
                max = risposta;
            } else if (conferma == '>') {
                min = risposta;
            }
        }
    }
}