#include <stdio.h>

	/*'	ALUNO: Antonio Claudio Teixeira Alves
	Crie um programa que contenha um array de float contendo 10 elementos.
	Imprima o endereco de cada posicao desse array.*/

int main() {
	float array[10];
	
	printf("Endereco de memoria de um array:\n");
	
	for(int i = 0; i < 10; i++) {
		printf("Posicao %d: %d\n", i+1, &array[i]);
	}
	
	return 0;
}
