#include <stdio.h>

	/*	ALUNO: Antonio Claudio Teixeira Alves
	Crie um programa que contenha um array contendo 5 elementos
	inteiros. Leia esse array do teclado e imprima o endereco das
	posicoes contendo valores pares.*/

int main() {
	int array[5];
	
	for(int i = 0; i < 5; i++) {
		printf("Valor %d: ", i + 1);
		scanf("%d", &array[i]);
	}
	
	printf("\n\nEndereco com numeros pares:\n");
	for(int i = 0; i < 5; i++) {
		if(array[i] % 2 == 0) {
			printf("Posicao %d: %d\n", i + 1, &array[i]);
		}
	}
	
	return 0;
}
