#include <stdio.h>
#include <stdlib.h>

void insertSort(int tamanho, int *vetor);

int main() {
	int vetor[100];
	
	printf("\n\t\t\t\t\tGERANDO UM VETOR COM TAMANHO 100\n\n");
	
	for(int i = 0; i < 100; i++) {
		vetor[i] = rand() % 150;
		
		printf("[%3d] ", vetor[i]);
	}
	
	insertSort(100, vetor);
	
	printf("\n\t\t\t\t\tORDENANDO O VETOR COM INSERT SORT\n\n");
	
	for(int i = 0; i < 100; i++) {
		printf("[%3d] ", vetor[i]);
	}
	
	printf("\n\nOBRIGADO POR USAR NOSSOS SERVICOS :)\n");
	
	return 0;
}

void insertSort(int tamanho, int *vetor) {
	int aux;
	
	for(int i = 1; i < tamanho; i++) {
		aux = vetor[i];
		
		for(int j = i; j != 0; j--) {
			
			if(vetor[j - 1] > vetor[j]) {
				vetor[j] = vetor[j - 1];
				vetor[j - 1] = aux;	
			} else {
				break;
			}
			
		}
		
	}
}
