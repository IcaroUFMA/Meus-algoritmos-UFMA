#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX 20

int main() {
	setlocale(LC_ALL, "Portuguese");
	int i = 0, j = 0;
	int pesquisa[2][MAX];

	for(i = 0; i < MAX ; i++)
		for(j = 0; j < 2; j++)
		{
			if(j == 0)
			{
				printf("Diga sua idade: ");
				scanf("%d",&pesquisa[j][i]);
			}
			if(j == 1)
			{
				do
				{
					printf("Diga o que achou do filme:\n (OTIMO:[10], BOM[9,7], REGULAR[6,5], RUIM[4,2], PESSIMO[1,0])\n");
					scanf("%d",&pesquisa[j][i]);
					if(pesquisa[j][i] > 10 || pesquisa[j][i] < 0)
						printf("Entrada irregular\n");
				}
				while(pesquisa[j][i] > 10 || pesquisa[j][i] < 0);
			}
		}
	printf("Tabela final da pesquisa: \nIDADE | AVALIAÇÃO\n");
	for(i = 0; i < MAX ; i++)
	{
		for(j = 0; j < 2; j++)
		{
			printf("%d\t",pesquisa[j][i]);
		}
		printf("\n");
	}
	printf("\n");

	int qtdOtimos = 0,qtdBons = 0, qtdRegulares = 0, qtdRuins = 0, qtdPessimos = 0;
	for(int i = 0 ; i < MAX ; i++)
	{

		if(pesquisa[1][i] == 10)
			qtdOtimos++;
		else if(pesquisa[1][i] < 10 && pesquisa[1][i] >= 7)
			qtdBons++;
		else if(pesquisa[1][i] < 7 && pesquisa[1][i] >= 5)
			qtdRegulares++;
		else if(pesquisa[1][i] < 5 && pesquisa[1][i] >= 2)
			qtdRuins++;
		else if(pesquisa[1][i] < 2 && pesquisa[1][i] >= 0)
			qtdPessimos++;
	}
	printf("Quantidade de otimos: %d\n",qtdOtimos);

	float percentualBomRegular = 100*((float)qtdBons/MAX - (float)qtdRegulares/MAX);
	if(percentualBomRegular > 0)
		printf("Há %.2f%% a mais de avaliações boas em comparação as regulares\n",percentualBomRegular);
	else if( percentualBomRegular < 0)
	{
		percentualBomRegular *= -1;
		printf("Há %.2f%% a mais de avaliações regulares em comparação as boas\n",percentualBomRegular);
	}

	int soma = 0,contador = 0;
	for(i = 0; i < MAX; i++)
	{
		if(pesquisa[1][i] < 5 && pesquisa[1][i] >= 2)
		{
			soma+= pesquisa[0][i];
			contador++;
		}
	}
	float media = (float)soma/contador;

	printf("Media de idade das pessoas que votaram ruim: %.1f\n",media);

	float percentualPessimos = 100*((float)qtdPessimos/MAX);
	int maiorIdadePessima = 0;
	for(i = 0; i < MAX; i++)
	{
		if(pesquisa[1][i] < 2 && pesquisa[1][i] >= 0)
			if(pesquisa[0][i] > maiorIdadePessima)
				maiorIdadePessima = pesquisa[0][i];
	}

	printf("Pessoa mais velha dentre as que avaliaram o filme como pessimo: %d\n",maiorIdadePessima);

	int maiorIdadeRuim = 0;
	for(i = 0; i < MAX; i++)
	{
		if(pesquisa[1][i] < 5 && pesquisa[1][i] >= 2)
			if(pesquisa[0][i] > maiorIdadeRuim)
				maiorIdadeRuim = pesquisa[0][i];
	}

	int menorIdadeRuim = maiorIdadeRuim;
	for(i = 0; i < MAX; i++)
	{
		if(pesquisa[1][i] < 5 && pesquisa[1][i] >= 2)
			if(pesquisa[0][i] < menorIdadeRuim)
				menorIdadeRuim = pesquisa[0][i];
	}

	int diferencaEntreMaiorEMenorRuim = maiorIdadeRuim - menorIdadeRuim;
	printf("Diferença de idade entre o mais velho e o mais novo que avaliaram o filme como ruim: %d",diferencaEntreMaiorEMenorRuim);

	return 0;
}