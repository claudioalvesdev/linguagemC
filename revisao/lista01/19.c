#include <stdio.h>

	/*	ALUNO: Antonio Claudio Teixeira Alves
	Escreva uma funcao que aceita como parametro um array de inteiros com N valores,
	e determina o maior elemento do array e o numero de vezes que este elemento ocorreu
	no array. Por exemplo, para um array com os seguintes elementos: 5, 2, 15, 3, 7, 15,
	8, 6, 15, a funcao deve retorna para o programa que a chamou o valor 15 e o numero 3
	(indicando que o numero 15 ocorreu 3 vezes). A funcao deve ser do tipo void.*/

void maiorNumero(int *array, int tamanho, int *maior, int *vezesRepete);

int main() {
	int quantidade, maiorValor, qtdRepetida;
	
	printf("Quantos elementos deseja cadastrar? ");
	scanf("%d", &quantidade);
	
	int vetor[quantidade];
	
	for(int i = 0; i < quantidade; i++) {
		printf("Valor %d: ", i + 1);
		scanf("%d", &vetor[i]);
	}
	
	maiorNumero(vetor, quantidade, &maiorValor, &qtdRepetida);
	
	printf("Maior Valor: %d\n", maiorValor);
	printf("Qtd de vezes repetida: %d", qtdRepetida);
	
	return 0;
}

void maiorNumero(int *array, int tamanho, int *maior, int *vezesRepete) {
	*maior = array[0];
	
	for(int i = 0; i < tamanho; i++) {
		if(array[i] > *maior) {
			*maior = array[i];
		}
	}
	
	for(int i = 0; i < tamanho; i++) {
		if(array[i] == *maior) {
			*vezesRepete = *vezesRepete + 1;
		}
		
	}
}
