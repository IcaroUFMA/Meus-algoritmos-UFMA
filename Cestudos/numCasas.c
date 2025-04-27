#include <stdio.h>
#include <stdlib.h>

int main() {

    int valor = 0;
    int casas = 0;

    printf("entre com um valor:");
    scanf("%d",&valor);

    while(valor!=0)
    {
        valor /=10;
        casas++;
    }
         printf("o numero de casas no valor inserido: %d ",casas);

    return 0;
}