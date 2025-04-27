#include <stdio.h>
#include <locale.h>
#define MAX 100

void lerString(char string[])
{
    int i =0;

    printf("Insira sua palavra: ");
    fgets(string,MAX,stdin);

    while(string[i]!= '\n')
    {
        i++;
    }
    string[i] = '\0';
}

void concatenaPalavra(char string[],char string2[])
{
    char stringFinal[MAX];
    int i = 0, j = 0;

    while(string[i] != '\0')
    {
        stringFinal[i] = string[i];
        i++;
    }

    while(string2[j] != '\0')
    {
        stringFinal[i+j] = string2[j];
        j++;
    }
    stringFinal[i+j] = '\0';
    puts(stringFinal);
}
int main() {

   setlocale(LC_ALL, "Portuguese");
   char palavra[MAX];
   char palavra2[MAX];
   int tamanhoString1,tamanhoString2;

   lerString(palavra);
   lerString(palavra2);

   concatenaPalavra(palavra,palavra2);
    return 0;
}