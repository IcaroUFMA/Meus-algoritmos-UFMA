#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX 100

int main() {
	setlocale(LC_ALL, "Portuguese");
	char frase[MAX],palavraDesejada[MAX], fraseFinal[MAX];
	int tamanhoDaString,tamanhoDaPalavra, i = 0, j = 0, k = 0,z = 0, posicaoDesejada = 0;

	printf("Insira sua string:");
	fgets(frase,MAX,stdin);

	printf("Insira sua substring que deseja adicionar:");
	fgets(palavraDesejada,MAX,stdin);

	do
	{
		printf("Insira onde deseja colocar a substring:\n1: No inicio\n2: No meio\n3: No fim\n");
		scanf("%d",&posicaoDesejada);
		if(posicaoDesejada < 1 || posicaoDesejada > 3)
		{
			printf("Entrada invalida tente denovo.\n\n");
		}
	}
	while(posicaoDesejada < 1 || posicaoDesejada > 3);

	tamanhoDaString = strlen(frase);

	while(i < tamanhoDaString)
	{
		if(frase[i] == '\n')
			frase[i] = '\0';
		i++;
	}
	tamanhoDaString--;

	tamanhoDaPalavra = strlen(palavraDesejada);

	i = 0;
	while(i < tamanhoDaPalavra)
	{
		if(palavraDesejada[i] == '\n')
			palavraDesejada[i] = '\0';
		i++;
	}
	tamanhoDaPalavra--;

	switch(posicaoDesejada)
	{
	case 1:

		for(j = 0; j < tamanhoDaPalavra; j++)
		{
			fraseFinal[j] = palavraDesejada[j];
		}
		for(k = 0; k <tamanhoDaString; k ++)
		{
			fraseFinal[j+k] = frase[k];
		}
		fraseFinal[j+k] = '\0';
		puts(fraseFinal);
		break;

	case 2:

		for(j = 0; j < tamanhoDaString/2; j++)
		{
			fraseFinal[j] = frase[j];
		}
		for(k = 0; k < tamanhoDaPalavra; k++)
		{
			fraseFinal[j+k] = palavraDesejada[k];
		}
		for(i = tamanhoDaString/2; i < tamanhoDaString; i++, z++)
		{
			fraseFinal[j+k+z] = frase[i];
		}
		fraseFinal[j+k+z] = '\0';
		puts(fraseFinal);
		break;

	case 3:

		for(j = 0; j < tamanhoDaString; j++)
		{
			fraseFinal[j] = frase[j];
		}
		for(k = 0; k <tamanhoDaPalavra; k ++)
		{
			fraseFinal[j+k] = palavraDesejada[k];
		}
		fraseFinal[j+k] = '\0';
		puts(fraseFinal);
	}

	return 0;
}