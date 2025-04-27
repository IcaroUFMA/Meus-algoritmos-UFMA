#include <stdio.h>
#include <string.h>
#include <locale.h>
#define MAX 200

int main() {
	char str[MAX];
	int n, i, len;

	setlocale(LC_ALL, "Portuguese");

	printf("Digite a string: ");
	fgets(str, MAX, stdin);
	str[strcspn(str, "\n")] = '\0'; // usando pra tirar o \n pq deu preguiça de fazer do 0

	printf("Digite o número de posições para rotacionar: ");
	scanf("%d", &n);

	len = strlen(str);

	n = n % len;

	char temp[MAX];

	for (i = 0; i < n; i++)
	{
		temp[i] = str[len - n + i];
	}

	for (i = 0; i < len - n; i++)
	{
		temp[n + i] = str[i];
	}

	temp[len] = '\0';

	printf("String após rotação: %s\n", temp);

	return 0;
}