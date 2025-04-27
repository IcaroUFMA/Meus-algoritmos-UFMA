#include <stdio.h>
#include <string.h>
#define MAX 4

int main() {
	char matriz[MAX][MAX];
	int contadorL = 0;
	int contadorC = 0;
	printf("Entre com a matriz %d x %d:\n",MAX,MAX);
	for(int i = 0; i < MAX; i++)
	{
		for(int j = 0; j < MAX; j++)
		{
			printf("A[%d][%d]: ",i+1,j+1);
			scanf(" %c",&matriz[i][j]);
		}
	}

	for(int i = 0; i < MAX; i++)
	{
		for(int j = 0; j < MAX; j++)
			printf(" %c",matriz[i][j]);

		printf("\n");
	}

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {

			if (j <= MAX - 3 && matriz[i][j] == 'a' && matriz[i][j+1] == 'n' && matriz[i][j+2] == 'a') {
				contadorL++;
			}

			if (i <= MAX - 3 && matriz[i][j] == 'a' && matriz[i+1][j] == 'n' && matriz[i+2][j] == 'a') {
				contadorC++;
			}
		}
	}
	printf("o padrao ana foi encontrado %d vez(es) na linha e %d vez(es) na coluna",contadorL,contadorC);

	return 0;
}