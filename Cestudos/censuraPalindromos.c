#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX 100

int main() {
	setlocale(LC_ALL, "Portuguese");
	char frase[MAX], palavra[MAX], palavraInvertida[MAX];
	int tamanho, i = 0, j = 0, k = 0, maxTamanho = 0, qtdPalindromos = 0;;
	int inicioPalindromos[MAX];

	printf("Esse algoritimo censura palindormos.\n");
	printf("Insira sua frase: ");
	fgets(frase, MAX, stdin);

	tamanho = strlen(frase);
	while (i < tamanho)
	{
		if (frase[i] == '\n')
		{
			frase[i] = '\0';
		}
		i++;
	}
	tamanho--;

	for (i = 0; i < tamanho; i++)
	{

		if (frase[i] != ' ')
		{

			for (j = 0; frase[i + j] != ' ' && frase[i + j] != '\0'; j++)
			{
				palavra[j] = frase[i + j];
			}
			palavra[j] = '\0';

			for (int m = 0; m < j; m++)
			{
				palavraInvertida[m] = palavra[j - m - 1];
			}
			palavraInvertida[j] = '\0';

			if (strcmp(palavra, palavraInvertida) == 0)
			{
				if (j > maxTamanho)
				{
					maxTamanho = j;
					qtdPalindromos = 0;
					inicioPalindromos[qtdPalindromos++] = i;
				}
				else if (j == maxTamanho)
					inicioPalindromos[qtdPalindromos++] = i;
			}
			
			i += j - 1;
		}
	}

	for (k = 0; k < qtdPalindromos; k++)
	{
		for (i = inicioPalindromos[k]; i < inicioPalindromos[k] + maxTamanho; i++)
			frase[i] = '*';
	}

	printf("Frase censurada: %s\n", frase);

	return 0;
}