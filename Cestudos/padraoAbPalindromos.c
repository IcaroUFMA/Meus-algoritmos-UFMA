#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int main() {
    char string[MAX];
    int tamanhoString, i=0,j=0,k=0;

    printf("Este algoritimo procura o padrão 'ab' em palindromos e os tranforma em xy.\nInsira sua string:\n");
    fgets(string,MAX,stdin);

    tamanhoString = strlen(string);

    if(string[tamanhoString-1] == '\n')
        string[tamanhoString-1] = '\0';
    tamanhoString--;

    int ehPalindromo;
    char palavra[MAX],palavraInvertida[MAX];

    for(i = 0; i< tamanhoString ; i++)
    {
        if(string[i]!= ' ')
        {
            for(j = 0; string[i+j] != ' ' && string[i+j] != '\0'; j++)
                palavra[j] = string[i+j];
            palavra[j] = '\0';

            for(k = 0; k < j ; k++)
                palavraInvertida[k] = palavra[j-k-1];
            palavraInvertida[k] = '\0';

            ehPalindromo = 1;
            for(int z = 0; z < k ; z++)
            {
                if(palavraInvertida[z] != palavra[z])
                {
                    ehPalindromo = 0;
                    break;
                }
            }
            if(ehPalindromo)
            {
                for(int m = 0; m < j - 1; m++)
                {
                    char c1 = tolower(string[i + m]);
                    char c2 = tolower(string[i + m + 1]);
                    if ((c1 == 'a' && c2 == 'b'))
                    {
                        string[i + m] = 'x';
                        string[i + m + 1] = 'y';
                    }
                }
            }
            i+= j - 1;
        }
    }
    puts(string);

    return 0;
}