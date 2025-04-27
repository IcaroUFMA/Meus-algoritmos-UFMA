#include <stdio.h>

int main() {
    int valor = 0;
    int pares = 0;
    int duplas = 0;
    int armazena = 0;
    int diferenca = 0;
    int soma = 0;
    
    printf("Insira um numero:\n");
    scanf("%d",&valor);

    armazena = valor;

    while(armazena!=0)
    {
        armazena /=100;
        duplas++;
    }

    armazena = valor;
    for(int i = 0; i < duplas; i++)
    {
        pares = armazena % 100;
        diferenca = (pares/10) - (pares%10);
        armazena /= 100;
        soma +=  diferenca;
    }
    printf("\n Soma das diferencas dos pares dos digitos  do numero inserido: %d",soma);
    return 0;
}