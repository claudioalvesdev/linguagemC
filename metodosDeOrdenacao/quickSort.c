#include <stdio.h>
#include <stdlib.h>

void quickSort(int tamanho, int *vetor);

int main() {
	int tamanho = 40000;
	int vetor[tamanho];
	
	/* 1º TESTE COM VETOR GERARDO RANDOMICAMENTE */
	/*
	printf("\n\t\t\t\t\tGERANDO UM VETOR RANDOMICAMENTE\n\n");
	
	for(int i = 0; i < tamanho; i++) {
		vetor[i] = rand();
		
		printf("[%d] ", vetor[i]);
	}
	
	quickSort(tamanho, vetor);
	
	printf("\n\t\t\t\t\tORDENANDO O VETOR COM QUICK SORT\n\n");
	
	for(int i = 0; i < tamanho; i++) {
		printf("[%d] ", vetor[i]);
	}
	*/
	
	
	printf("\n\t\t\t\t\tGERANDO UM VETOR CRESCENTEMENTE\n\n");
	
	for(int i = 0; i < tamanho; i++) {
		vetor[i] = i;
		
		printf("[%d] ", vetor[i]);
	}
	
	quickSort(tamanho, vetor);
	
	printf("\n\t\t\t\t\tORDENANDO O VETOR COM QUICK SORT\n\n");
	
	for(int i = 0; i < tamanho; i++) {
		printf("[%d] ", vetor[i]);
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
				ultimosIndices--;
			}
			
		} while(primeirosIndices <= ultimosIndices);
		
		vetor[0] = vetor[ultimosIndices];
		vetor[ultimosIndices] = pivo;
		
		quickSort(ultimosIndices, vetor);
		quickSort((tamanho - primeirosIndices), &vetor[primeirosIndices]);
	}
}
