#include <stdio.h>

	/*	ALUNO: Antonio Claudio Teixeira Alves
	Crie um programa que contenha uma matriz de float contendo 3 linhas
	e 3 colunas. Imprima o endereco de cada posicao dessa matriz.*/

int main() {
	float matriz[3][3];
	
	
	printf("Endereco de memoria de uma matriz\n");
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			printf("[%d][%d]: %d\n", i+1, j+1, &matriz[i][j]);
		}
	}
	
	
	return 0;
}
