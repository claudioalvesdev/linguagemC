#include <stdio.h>

	/*	ALUNO: Antonio Claudio Teixeira Alves
	Crie um programa que contenha um array de inteiros contendo 5 elementos. 
	Utilizando apenas aritmetica de ponteiros, leia esse array do teclado e 
	imprima o dobro de cada valor lido.*/

int main() {
	int array[5];
	int *ponteiro;
	
	ponteiro = &array[0];
	
	for(int i = 0; i < 5; i++) {
		printf("Valor %d: ", i + 1);
		scanf("%d", &*(ponteiro + i));
	}
	
	printf("\n\tDOBRO DE CADA ELEMENTO\n");
	for(int i = 0; i < 5; i++) {
		printf("Valor %d: %d\n", i + 1, *(ponteiro + i) * 2);
	}
	
	return 0;
}
