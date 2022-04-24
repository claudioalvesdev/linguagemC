#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int tamanho, int *vetor);

int main() {
	int vetor[100];
	
	printf("\n\t\t\t\t\tGERANDO UM VETOR COM TAMANHO 100\n\n");
	
	for(int i = 0; i < 100; i++) {
		vetor[i] = rand() % 150;
		
		printf("[%3d] ", vetor[i]);
	}
	
	bubbleSort(100, vetor);
	
	printf("\n\t\t\t\t\tORDENANDO O VETOR COM BUBBLE SORT\n\n");
	
	for(int i = 0; i < 100; i++) {
		printf("[%3d] ", vetor[i]);
	}
	
	printf("\n\nOBRIGADO POR USAR NOSSOS SERVICOS :)\n");
	
	return 0;
}

void bubbleSort(int tamanho, int *vetor) {
	int aux;
	
	for(int i = tamanho - 1; i >= 1; i--) {
		
		for(int j = 0; j < i; j++) {
			
			if(vetor[j] > vetor[j +1]) {
				aux = vetor[j];
				vetor[j] = vetor[j + 1];
				vetor[j + 1] = aux;
			}
			
		}
		
	}
}
