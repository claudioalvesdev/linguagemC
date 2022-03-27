#include <stdio.h>
	
	/*	ALUNO: Antonio Claudio Teixeira Alves
	Crie uma funcao que receba como parametro um array e o imprima. 
	Nao utilize indices para percorrer o array, apenas aritmetica de
	ponteiros.*/

void imprimir(int *array) {
	for(int i = 0; i < 5; i++) {
		printf("[%d] ", *(array + i));
	}
}

int main() {
	int vetor[5], *p;
	
	p = &vetor[0];
	
	for(int i = 0; i < 5; i++) {
		printf("Valor %d: ", i + 1);
		scanf("%d", &*(p + i));
	}
	
	printf("\n\n\n");
	
	imprimir(vetor);
	
	return 0;
}
