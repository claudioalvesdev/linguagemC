#include <stdio.h>
#include <stdlib.h>

void quickSort(int tamanho, int *vetor);

int main() {
	int vetor[100];
	
	printf("\n\t\t\t\t\tGERANDO UM VETOR COM TAMANHO 100\n\n");
	
	for(int i = 0; i < 100; i++) {
		vetor[i] = rand() % 150;
		
		printf("[%3d] ", vetor[i]);
	}
	
	quickSort(100, vetor);
	
	printf("\n\t\t\t\t\tORDENANDO O VETOR COM QUICK SORT\n\n");
	
	for(int i = 0; i < 100; i++) {
		printf("[%3d] ", vetor[i]);
	}
	
	printf("\n\nOBRIGADO POR USAR NOSSOS SERVICOS :)\n");
	
	return 0;
}

void quickSort(int tamanho, int *vetor) {
	
	if(tamanho <= 1) {
		return;
	} else {
		int pivo = vetor[0];
		int primeirosIndices = 1;
		int ultimosIndices = tamanho - 1;
		
		do{
			while(primeirosIndices < tamanho && vetor[primeirosIndices] <= pivo) {
				primeirosIndices++;
			}
			
			while(vetor[ultimosIndices] > pivo) {
				ultimosIndices--;
			}
			
			if(primeirosIndices < ultimosIndices) {
				int aux = vetor[primeirosIndices];
				vetor[primeirosIndices] = vetor[ultimosIndices];
				vetor[ultimosIndices] = aux;
				
				primeirosIndices++;
				ultimosIndices++;
			}
			
		} while(primeirosIndices <= ultimosIndices);
		
		vetor[0] = vetor[ultimosIndices];
		vetor[ultimosIndices] = pivo;
		
		quickSort(ultimosIndices, vetor);
		quickSort(tamanho - primeirosIndices, &vetor[primeirosIndices]);
	}
}
