#include <stdio.h>
#include <stdlib.h>

int main() {

    int valor = 0;
    int copiaValor;
    int casas = 0;
    int vezes = 0;
    int desejado = 0;
    int referencia = 0;

    printf("entre com um valor:");
    scanf("%d",&valor);


    copiaValor = valor;

       while (copiaValor != 0) {
        copiaValor /= 10;
        casas++;
    }
    copiaValor = valor;
       printf("Entre com o numero que queira contar: ");
    scanf("%d", &desejado);

    for(int i = casas ; i > 0; i--)
    {
        referencia = copiaValor % 10;
        copiaValor /= 10;

        if( referencia == desejado)
        {
            vezes++;
        }
    }

    printf("O numero: %d apareceu: %d veze(s)\n",desejado,vezes);


    return 0;
}