#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int tamanho, int *vetor);

int main() {
	int tamanho = 100000;
	int vetor[tamanho];
	
	
	/* 1º TESTE COM VETOR GERARDO RANDOMICAMENTE */
	/*
	printf("\n\t\t\t\t\tGERANDO UM VETOR RANDOMICAMENTE\n\n");
	
	for(int i = 0; i < 100000; i++) {
		vetor[i] = rand();
		
		printf("[%d] ", vetor[i]);
	}
	
	bubbleSort(100000, vetor);
	
	printf("\n\t\t\t\t\tORDENANDO O VETOR COM BUBBLE SORT\n\n");
	
	for(int i = 0; i < 100000; i++) {
		printf("[%d] ", vetor[i]);
	}
	*/
	
	
	/* 2ª TESTE COM VETOR GERARDO CRESCENTEMENTE *?
	
	/*
	printf("\n\t\t\t\t\tCRIANDO VETOR CRESCEMENTE\n\n");
	
	for(int i = 0; i < tamanho; i++) {
		vetor[i] = i;
		
		printf("[%d] ", vetor[i]);
	}
	
	bubbleSort(tamanho, vetor);
	
	printf("\n\t\t\t\t\tORDENANDO O VETOR COM BUBBLE SORT\n\n");
	
	for(int i = 0; i < tamanho; i++) {
		printf("[%d] ", vetor[i]);
	}
	*/
	
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
