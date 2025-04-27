#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int main() {
    char texto[MAX], textoAnalise[MAX];
    

    printf("Digite uma string:\n");
    fgets(texto, sizeof(texto), stdin);

    if (texto[strlen(texto) - 1] == '\n') 
        texto[strlen(texto) - 1] = '\0';

    printf("Digite uma substring que queira encontrar na string:\n");
    fgets(textoAnalise, sizeof(textoAnalise), stdin);

    int tamanhoAnalise = strlen(textoAnalise);
    if (textoAnalise[tamanhoAnalise - 1] == '\n') 
        textoAnalise[tamanhoAnalise - 1] = '\0';
    

    int contador = 0;
    int tamanhoTexto = strlen(texto);
    tamanhoAnalise = strlen(textoAnalise);

    for(int i = 0 ; i <= strlen(texto) - tamanhoAnalise ; i++)
    {
        int encontrou = 1;
        if(texto[i] != ' ')
            for(int j = 0; j < strlen(textoAnalise);j++)
            {
                if(i+j < strlen(texto) )
                {
                    if(texto[i+j] != textoAnalise[j])
                    {
                        encontrou = 0;
                        break;
                    }
                    else
                    {
                        encontrou = 1;
                    }
                }
                else
                    break;
            }
            else
            {
                encontrou = 0;
            }
        if(encontrou)
                {
                    contador++;
                }
    }

    printf("%d",contador);

    return 0;
}