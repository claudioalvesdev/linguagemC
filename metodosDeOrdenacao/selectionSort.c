#include <stdio.h>
#include <stdlib.h>

void selectionSort(int tamanho, int *vetor);

int main() {
	int vetor[100];
	
	printf("\n\t\t\t\t\tGERANDO UM VETOR COM TAMANHO 100\n\n");
	
	for(int i = 0; i < 100; i++) {
		vetor[i] = rand() % 150;
		
		printf("[%3d] ", vetor[i]);
	}
	
	selectionSort(100, vetor);
	
	printf("\n\t\t\t\t\tORDENANDO O VETOR COM INSERT SORT\n\n");
	
	for(int i = 0; i < 100; i++) {
		printf("[%3d] ", vetor[i]);
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
