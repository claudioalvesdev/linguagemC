#include <stdio.h>
#include <stdlib.h>

void mergeSort(int tamanho, int *vetor);

void merge(int *vetor, int *copiaDoVetor, int inicio, int meio, int fim);

void sort(int *vetor, int *copiaDoVetor, int inicio, int fim);

int main() {
	int tamanho = 100000;
	int vetor[tamanho];
	
	
	/* 1º TESTE COM VETOR GERADO RANDOMICAMENTE */
	/*
	printf("\n\t\t\t\t\tGERANDO UM VETOR RANDOMICAMENTE\n\n");
	
	for(int i = 0; i < tamanho; i++) {
		vetor[i] = rand();
		
		printf("[%d] ", vetor[i]);
	}
	
	mergeSort(tamanho, vetor);
	
	printf("\n\t\t\t\t\tORDENANDO O VETOR COM MERGE SORT\n\n");
	
	for(int i = 0; i < tamanho; i++) {
		printf("[%d] ", vetor[i]);
	}
	*/
	
	/* 2º TESTE COM VETOR GERADO CRESCENTEMENTE */
	/*
	printf("\n\t\t\t\t\tGERANDO UM VETOR CRESCENTEMENTE\n\n");
	
	for(int i = 0; i < tamanho; i++) {
		vetor[i] = i;
		
		printf("[%d] ", vetor[i]);
	}
	
	mergeSort(tamanho, vetor);
	
	printf("\n\t\t\t\t\tORDENANDO O VETOR COM MERGE SORT\n\n");
	
	for(int i = 0; i < tamanho; i++) {
		printf("[%d] ", vetor[i]);
	}
	*/
	
	/* 3ª TESTE COM VETOR GERADO DECRESCENTEMENTE */
	/*
	printf("\n\t\t\t\t\tCRIANDO VETOR DECRESCEMENTE\n\n");
	
	for(int i = tamanho; i >= 0; i--) {
		vetor[i] = tamanho - i;
		
		printf("[%d] ", vetor[i]);
	}
	
	mergeSort(tamanho, vetor);
	
	printf("\n\t\t\t\t\tORDENANDO O VETOR COM MERGE SORT\n\n");
	
	for(int i = 0; i < tamanho; i++) {
		printf("[%d] ", vetor[i]);
	}
	*/
	
	return 0;
}

void mergeSort(int tamanho, int *vetor) {
	int *copiaDoVetor = malloc(sizeof(int)*tamanho);
	sort(vetor, copiaDoVetor, 0, tamanho - 1);
	free(copiaDoVetor);
}

void merge(int *vetor, int *copiaDoVetor, int inicio, int meio, int fim) {
	int z, iv = inicio, ic = meio + 1;
	
	for(z = inicio; z <= fim; z++) {
		copiaDoVetor[z] = vetor[z];
	}
	
	z = inicio;
	
	while(iv <= meio  && ic <= fim) {
		if(copiaDoVetor[iv] <= copiaDoVetor[ic]) {
			vetor[z] = copiaDoVetor[iv];
			z++;
			iv++;
		} else {
			vetor[z] = copiaDoVetor[ic];
			z++;
			ic++;
		}
	}
	
	while(iv <= meio) {
		vetor[z++] = copiaDoVetor[iv++];
	}
	
	while(ic <= fim) {
		vetor[z++] = copiaDoVetor[ic++];
	}
}

void sort(int *vetor, int *copiaDoVetor, int inicio, int fim) {
	if(inicio >= fim) {
		return;
	}
	
	int meio = (inicio + fim)/2;
	
	sort(vetor, copiaDoVetor, inicio, meio);
	sort(vetor, copiaDoVetor, meio + 1, fim);
	merge(vetor, copiaDoVetor, inicio, meio, fim);
}


