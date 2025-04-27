#include <stdio.h>
#include <locale.h>
#define MAX 100

void lerString(char string[])
{
    int i =0;
    
    printf("Este algoritimo compacta a sua string, exemplo: arara -> a3r2\n");
    printf("Insira sua palavra: ");
    fgets(string,MAX,stdin);

    while(string[i]!= '\n')
    {
        i++;
    }
    string[i] = '\0';
}

void navegaString(char string[])
{
    int alfabeto[256] = {0};
    int frequencia[256] = {0};

    int i,contador = 0;
    for(i = 0; string[i] != '\0'; i++)
    {
        
        if(alfabeto[(int)string[i]] == 0)
            alfabeto[(int)string[i]] = 1;
        if(alfabeto[(int)string[i]] == 1)
        {
            frequencia[(int)string[i]] += 1;
        }
    }
    imprimirVetor(string,alfabeto,frequencia);
}

void imprimirVetor(char string[],int letras[], int vezesAparecem[])
{
    int i = 0;
    while(string[i] != '\0')
    {
        if(letras[(int)string[i]] == 1)
        {
            printf("%c",string[i]);
            printf("%d",vezesAparecem[(int)string[i]]);
            letras[(int)string[i]] = 0;
        }
        i++;
    }
}
int main() {

   setlocale(LC_ALL, "Portuguese");
   char palavra[MAX];
   int tamanhoString1,tamanhoString2;

   lerString(palavra);
   navegaString(palavra);
   return 0;
}