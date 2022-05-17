#include <stdio.h>
#include <stdlib.h>

void selectionSort(int tamanho, int *vetor);

int main() {
	int tamanho = 100000;
	int vetor[tamanho];
	
	/* 1º TESTE COM VETOR GERARDO RANDOMICAMENTE */
	/*
	printf("\n\t\t\t\t\tGERANDO UM VETOR RANDOMICAMENTE\n\n");
	
	for(int i = 0; i < tamanho; i++) {
		vetor[i] = rand();
		
		printf("[%d] ", vetor[i]);
	}
	
	selectionSort(tamanho, vetor);
	
	printf("\n\t\t\t\t\tORDENANDO O VETOR COM INSERT SORT\n\n");
	
	for(int i = 0; i < tamanho; i++) {
		printf("[%d] ", vetor[i]);
	}
	*/
	
	printf("\n\t\t\t\t\tGERANDO UM VETOR CRESCENTEMENTE\n\n");
	
	for(int i = 0; i < tamanho; i++) {
		vetor[i] = i;
		
		printf("[%d] ", vetor[i]);
	}
	
	selectionSort(tamanho, vetor);
	
	printf("\n\t\t\t\t\tORDENANDO O VETOR COM INSERT SORT\n\n");
	
	for(int i = 0; i < tamanho; i++) {
		printf("[%d] ", vetor[i]);
	}
	
	printf("\n\nOBRIGADO POR USAR NOSSOS SERVICOS :)\n");
	
	return 0;
}

void selectionSort(int tamanho, int *vetor) { 
  int menorIndice, aux;
  
  for(int i = 0; i < tamanho - 1; i++) {
     menorIndice = i;
     
     for(int j = i + 1; j < tamanho; j++) {
		if(vetor[j] < vetor[menorIndice]) {
	 		menorIndice = j;
		}
     }
     
     if (i != menorIndice) {
       aux = vetor[i];
       vetor[i] = vetor[menorIndice];
       vetor[menorIndice] = aux;
     }
  }
  
}
