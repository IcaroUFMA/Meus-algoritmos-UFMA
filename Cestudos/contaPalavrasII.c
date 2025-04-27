#include <stdio.h>
#include <locale.h>
#define MAX 100
#define MAX_PALAVRAS 20 
#define MAX_TAM_PALAVRA 20

int main() 
{
    char frase[MAX];
    char palavras[MAX_PALAVRAS][MAX_TAM_PALAVRA]; 
    int i = 0, j = 0, k = 0, contador = 0;
    int dentro_palavra = 0; 

    setlocale(LC_ALL, "Portuguese");

    printf("Insira uma frase: ");
    fgets(frase, MAX, stdin);

    while (frase[i] != '\0') 
    {
        if (frase[i] == '\n') 
        {
            frase[i] = '\0';
            break;
        }
        i++;
    }


    for (i = 0; frase[i] != '\0'; i++) {
        if (frase[i] != ' ' && dentro_palavra == 0) 
        {
            dentro_palavra = 1;
            k = 0; 
        }

        if (dentro_palavra) 
        {
            palavras[contador][k++] = frase[i]; 
        }

        if (frase[i] == ' ' || frase[i] == '\0') 
        {

            if (dentro_palavra) 
            {
                palavras[contador][k] = '\0'; 
                contador++; 
                dentro_palavra = 0; 
            }
        }
    }

    if (dentro_palavra) {
        palavras[contador][k] = '\0'; 
        contador++; 
    }

    printf("A frase contém %d palavra(s):\n", contador);
    for (i = 0; i < contador; i++) {
        printf("Palavra %d: %s\n", i + 1, palavras[i]);
    }

    return 0;
}