#include <stdio.h>
#include <locale.h>
#define MAX 100

int main() {
	char frase[MAX];
	int i = 0, contador = 0;
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

	for (i = 0; frase[i] != '\0'; i++)
	{
		if (frase[i] != ' ' && dentro_palavra == 0)
		{
			contador++;
			dentro_palavra = 1;
		}

		else if (frase[i] == ' ')
		{
			dentro_palavra = 0;
		}
	}

	printf("A frase tem %d palavra(s).\n", contador);

	return 0;
}