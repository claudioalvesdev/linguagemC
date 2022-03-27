#include <stdio.h>

	/*	ALUNO: Antonio Claudio Teixeira Alves
	Crie uma funcao que receba dois parametros: um array e um valor
	do mesmo tipo do array. A funcao devera preencher os elementos
	de array com esse valor. Nao utilize indices para percorrer o 
	array, apenas aritmetica de ponteiros.*/
	
void preencherVetor(int n, int *vetor);

int main() {
	int valores[5], numero;
	
	printf("Digite um valor: ");
	scanf("%d", &numero);
	
	preencherVetor(numero, valores);
	
	for(int i = 0; i < 5; i++) {
		printf("[%d] ", valores[i]);
	}
	
	
	return 0;
}

void preencherVetor(int n, int *vetor) {
	for(int i = 0; i < 5; i++) {
		*(vetor + i) = n;
	}
}
