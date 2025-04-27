#include <stdio.h>
#include <string.h>

#define MAX 100
int main() {
    char string[MAX], subString[MAX], stringFinal[MAX];
    int tamanhoString, tamanhoSubString;
    int i, j, k, encontrou;

    printf("Insira a string principal: ");
    fgets(string, MAX, stdin);
    if (string[strlen(string) - 1] == '\n') 
    {
        string[strlen(string) - 1] = '\0';
    }

    printf("Insira a substring a ser removida: ");
    fgets(subString, MAX, stdin);
    if (subString[strlen(subString) - 1] == '\n') 
    {
        subString[strlen(subString) - 1] = '\0';
    }

    tamanhoString = strlen(string);
    tamanhoSubString = strlen(subString);

    int posicaoFinal = 0; 

    for (i = 0; i < tamanhoString; i++) 
    {
        encontrou = 1; 

        for (j = 0; j < tamanhoSubString; j++) {
            if (i + j >= tamanhoString || string[i + j] != subString[j]) 
            {
                encontrou = 0; 
                break;
            }
        }
        if (encontrou) 
        {
            i += tamanhoSubString - 1;
        } 
        else 
        {
            stringFinal[posicaoFinal] = string[i];
            posicaoFinal++;
        }
    }
    stringFinal[posicaoFinal] = '\0';


    printf("String resultante: %s\n", stringFinal);

    return 0;
}