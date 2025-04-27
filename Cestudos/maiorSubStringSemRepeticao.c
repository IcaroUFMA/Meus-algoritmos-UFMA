#include <stdio.h>
#include <string.h>

#define MAX_CHAR 256

int main() {
    char str[100];
    int tabela[MAX_CHAR] = {0}; 
    int inicio = 0;             
    int maxLen = 0;             
    int inicioMax = 0;      
    int n;

    printf("Digite uma string: ");
    scanf("%s", str);
    n = strlen(str);

    for (int i = 0; i < n; i++) {
        
        if (tabela[str[i]] > inicio) {
            inicio = tabela[str[i]];
        }
        
        tabela[str[i]] = i + 1;

        if (i - inicio + 1 > maxLen) 
        {
            maxLen = i - inicio + 1;
            inicioMax = inicio;
        }
    }

    printf("Maior substring sem caracteres repetidos: ");
    for (int i = inicioMax; i < inicioMax + maxLen; i++) {
        putchar(str[i]);
    }
    printf("\nComprimento: %d\n", maxLen);

    return 0;
}