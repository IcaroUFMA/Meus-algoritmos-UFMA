#include <stdio.h>
#include <ctype.h>

#define MAX 200

int main() {
    char original[MAX], busca[MAX], substitui[MAX];
    char resultado[MAX];
    int i = 0, j = 0, k = 0;
    int tam_busca = 0, tam_substitui = 0;

    printf("Digite a string original: ");
    fgets(original, MAX, stdin);
    while (original[i] != '\n' && original[i] != '\0') i++;
    original[i] = '\0';

    printf("Digite a substring a buscar: ");
    fgets(busca, MAX, stdin);
    i = 0;
    while (busca[i] != '\n' && busca[i] != '\0') i++;
    busca[i] = '\0';
    while (busca[tam_busca] != '\0') tam_busca++;

    printf("Digite a substring substituta: ");
    fgets(substitui, MAX, stdin);
    i = 0;
    while (substitui[i] != '\n' && substitui[i] != '\0') i++;
    substitui[i] = '\0';
    while (substitui[tam_substitui] != '\0') tam_substitui++;

    i = 0;
    while (original[i] != '\0') {
        int igual = 1;
        for (k = 0; k < tam_busca; k++) {
            if (tolower(original[i+k]) != tolower(busca[k])) {
                igual = 0;
                break;
            }
        }

        if (igual && tam_busca > 0) {
            for (k = 0; k < tam_substitui; k++) {
                resultado[j++] = substitui[k];
            }
            i += tam_busca;
        } else {
            resultado[j++] = original[i++];
        }
    }

    resultado[j] = '\0';

    for (i = 0; resultado[i] != '\0'; i++) {
        original[i] = resultado[i];
    }
    original[i] = '\0';

    printf("Resultado: %s\n", original);

    return 0;
}