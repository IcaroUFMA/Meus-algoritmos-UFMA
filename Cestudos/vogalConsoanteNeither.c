#include <stdio.h>

int main() {
	char entrada[100];
	char primeiraLetra;

	printf("Digite uma palavra: ");
	scanf("%s", entrada);

	primeiraLetra = entrada[0];


	if (primeiraLetra == 'A' || primeiraLetra == 'E' || primeiraLetra == 'I' ||
	        primeiraLetra == 'O' || primeiraLetra == 'U' ||
	        primeiraLetra == 'a' || primeiraLetra == 'e' || primeiraLetra == 'i' ||
	        primeiraLetra == 'o' || primeiraLetra == 'u')
	{
		printf("A primeira letra '%c' é uma vogal.\n", primeiraLetra);
	}

	else if ((primeiraLetra >= 'A' && primeiraLetra <= 'Z') ||
	         (primeiraLetra >= 'a' && primeiraLetra <= 'z'))
	{
		printf("A primeira letra '%c' é uma consoante.\n", primeiraLetra);
	}

	else
	{
		printf("O caractere '%c' não é uma letra.\n", primeiraLetra);
	}

	return 0;
}