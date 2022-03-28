#include <stdio.h>

	/*	ALUNO: Antonio Claudio Teixeira Alves
	Escreva uma funcao que receba um array de inteiros V e os enderecos
	de duas variaveis inteiras, min e max, e armazene nessas variaveis o valor
	minimo e maximo do array. Escreva tambem uma funcao main que use essa
	funcao.*/

void maxMin(int *array, int *min, int *max, int tamanho);

int main() {
	int tamanho, maximo, minino;
	
	printf("Deseja inserir quantos elementos? ");
	scanf("%d", &tamanho);
	
	int vetor[tamanho];
	
	for(int i = 0; i < tamanho; i++) {
		printf("Valor %d: ", i + 1);
		scanf("%d", &vetor[i]);
	}
	
	maxMin(vetor, &maximo, &minino, tamanho);
	
	printf("\n\nMaximo: %d\n", maximo);
	printf("Minino: %d\n", minino);
	
	
	return 0;
}

void maxMin(int *array, int *min, int *max, int tamanho) {
	*max = array[0];
	*min = array[0];
	
	for(int i = 0; i < tamanho; i++) {
		if(*max > array[i]) {
			*max = array[i];
		}
		if(*min < array[i]) {
			*min = array[i];
		}
	}
}
