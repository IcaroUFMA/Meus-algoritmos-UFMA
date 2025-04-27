#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX 100

int main() {
    setlocale(LC_ALL, "Portuguese");
    int tamanho,i = 0,j =0, qtdMaiusculos = 0;
    char frase[MAX];
    char sigla[MAX];


    printf("Insira seu nome para obter a sua abreviação: ");

    fgets(frase,MAX,stdin);

    tamanho = strlen(frase);
    while(i < tamanho)
    {
        if(frase[i] == '\n')
            frase[i] = '\0';
        i++;
    }
    tamanho--;

    for(i = 0; i < tamanho; i++)
    {
        if(frase[i] != '\0' && frase[i] != ' ')
            for(j = 0; frase[i+j] != ' ' && frase[i+j] != '\0'; j++)
            {
                if(j > 2 || i == 0)
                {
                    if(frase[i] >= 65 && frase[i] <= 90)
                        sigla[qtdMaiusculos++] = frase[i];
                        break;
                }
            }

    }
    sigla[qtdMaiusculos] = '\0';

    tamanho = strlen(sigla);
    for(i = 0; i < tamanho ;i++)
    {
        if(i < tamanho-1)
            printf("%c.",sigla[i]);
        else
            printf("%c",sigla[i]);
    }
    return 0;
}