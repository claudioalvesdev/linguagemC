#include <stdio.h>

	/*	ALUNO: Antonio Claudio Teixeira Alves
	Escreva um programa que declare um array de inteiros e um ponteiro para inteiros. 
	Associe o ponteiro ao array. Agora, some mais um (+1) a cada posicao do array usando
	o ponteiro (use *).*/

int main() {
	int *ponteiro, quantidade;
	
	printf("Desejar inserir quantos numeros? ");
	scanf("%d", &quantidade);
	
	int vetor[quantidade];
	
	ponteiro = &vetor[0];
	
	printf("Digite os %d valores abaixo:\n", quantidade);
	for(int i = 0; i < quantidade; i++) {
		printf("Valor %d: ", i + 1);
		scanf("%d", &*(ponteiro + i));
	}
	
	for(int i = 0; i < quantidade; i++) {
		printf("[%d] ", *(ponteiro + i) + 1);
	}
	
	return 0;
}
