#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX 100

int main() {
    setlocale(LC_ALL, "Portuguese");
    char frase[MAX], palavra[MAX];
    int tamanho, i = 0, j = 0, k = 0, minTamanho = MAX, qtdPequenos = 0;;
    int inicioPequenos[MAX];

    printf("Insira sua string:");
    fgets(frase,MAX,stdin);

    tamanho = strlen(frase);

    while(i < tamanho)
    {
        if(frase[i] == '\n')
            frase[i] = '\0';
        i++;
    }
    tamanho--;

    for(i = 0; i < tamanho ; i++)
    {
        if(frase[i] != ' ')
        {
            for(j = 0; frase[i+j] != ' ' && frase[i+j] != '\0'; j++)
            {
                palavra[j] = frase[i+j];
            }
            palavra[j] = '\0';

            if(j < minTamanho)
            {
                minTamanho = j;
                qtdPequenos = 0;
                inicioPequenos[qtdPequenos++] = i;
            }
            else if(j == minTamanho)
            {
                inicioPequenos[qtdPequenos++] = i;
            }
            i += j;
        }
    }
    printf("Menor(es) palavras da string:\n");
    for(i = 0 ; i < qtdPequenos ; i++)
    {
        for(j = inicioPequenos[i] ; frase[j] != '\0' && frase[j] != ' ' ; j++)
        {
            printf("%c",frase[j]);
        }
        printf("\n");
    }

    return 0;
}