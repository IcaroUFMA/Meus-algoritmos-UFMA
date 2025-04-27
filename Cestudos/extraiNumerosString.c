#include <stdio.h>
#include <math.h>
#define MAX 100

void obterString(char string[]);
int extrairNumeros(const char string[], int numeros[], int *soma);
void imprimirResultado(const int numeros[], int contadorNumeros, int soma);

int main() {
    char string[MAX];
    int numeros[MAX] = {0};
    int soma = 0, contadorNumeros;

    obterString(string);
    contadorNumeros = extrairNumeros(string, numeros, &soma);
    imprimirResultado(numeros, contadorNumeros, soma);

    return 0;
}

void obterString(char string[]) {
    printf("Insira sua string:\n");
    fgets(string, MAX, stdin);

    int i = 0;
    while (string[i] != '\n' && string[i] != '\0') {
        i++;
    }
    string[i] = '\0';
}

int extrairNumeros(const char string[], int numeros[], int *soma) {
    int acumulador[MAX] = {0};
    int i, j, k, contadorNumeros = 0;

    *soma = 0;

    for (i = 0; string[i] != '\0'; i++) {
        if (string[i] >= '0' && string[i] <= '9') {
            j = 0;
            while (string[i] >= '0' && string[i] <= '9') {
                acumulador[j++] = string[i] - '0';
                i++;
            }
            i--;

            int valor = 0;
            for (k = 0; k < j; k++) {
                valor += acumulador[k] * pow(10, j - k - 1);
            }

            *soma += valor;
            numeros[contadorNumeros++] = valor;
        }
    }

    return contadorNumeros;
}

void imprimirResultado(const int numeros[], int contadorNumeros, int soma) {
    for (int i = 0; i < contadorNumeros; i++) {
        printf("%d", numeros[i]);
        if (i < contadorNumeros - 1) {
            printf(" + ");
        } else {
            printf(" = ");
        }
    }

    printf("%d\n", soma);
}