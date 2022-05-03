#include <stdio.h>
#include <stdlib.h>

void ordenarVetor(int tamanho, int *vetor);

int buscaBinaria(int tamanho, int *vetor, int valorDesejado);

int main() {
	int vetor[100], valorDesejado, indiceDesejado;
	
	printf("\n\t\t\t\tGERANDO UM VETOR COM TAMANHO 100\n\n");
	
	for(int i = 0; i < 100; i++) {
		vetor[i] = rand() % 150;
		
		printf("[%3d] ", vetor[i]);
	}
	
	ordenarVetor(100, vetor);
	
	printf("\n\t\t\t\t\tORDENANDO O VETOR COM INSERT SORT\n\n");
	
	for(int i = 0; i < 100; i++) {
		printf("[%3d] ", vetor[i]);
	}
	
	printf("\nDesejar procurar qual numero? ");
	scanf("%d", &valorDesejado);
	
	indiceDesejado = buscaBinaria(100, vetor, valorDesejado);
	
	if(indiceDesejado < 0) {
		printf("[ERRO] Numero nao encontrado x(\n");
	} else {
		printf("Encontrado o numero %d no indice: %d\n", valorDesejado, indiceDesejado);
	}
	
	return 0;
}

void ordenarVetor(int tamanho, int *vetor) {
	int aux;
	
	for(int i = 0; i < tamanho; i++) {
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

int buscaBinaria(int tamanho, int *vetor, int valorDesejado) {
	
}
