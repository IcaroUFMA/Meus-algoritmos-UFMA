#include <stdio.h>
#include <locale.h>
#define MAX 100

int main() {
	char palavra[MAX];
	int i = 0, j = 0;
	setlocale(LC_ALL, "Portuguese");

	printf("Insira uma palavra: ");
	fgets(palavra, MAX, stdin);


	while (palavra[i] != '\0')
	{
		if (palavra[i] == '\n')
		{
			palavra[i] = '\0';
			break;
		}
		i++;
	}

	for (i = 0; palavra[i] != '\0'; i++)
	{
		if (palavra[i] != ' ')
		{
			palavra[j] = palavra[i];
			j++;
		}
	}
	palavra[j] = '\0';

	printf("A palavra sem espaços: '%s'\n", palavra);

	return 0;
}