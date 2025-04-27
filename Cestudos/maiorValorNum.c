#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() 
{

    int valor = 0;
    int copiaValor;
    int casas = 0;
    int maiorNumero = 0;
    int referencia = 0;
    printf("entre com um valor:");
    scanf("%d",&valor);

    copiaValor = valor;

    while(copiaValor!=0)
    {
        copiaValor /=10;
        casas++;
    }
    copiaValor = valor;
    for(int i = casas ; i > 0; i--)
    {
        referencia = (copiaValor % 10);
        copiaValor /= 10;

        if(referencia > maiorNumero)
            maiorNumero = referencia;
    }
         printf("o maior digito do numero: %d ",maiorNumero);
}   