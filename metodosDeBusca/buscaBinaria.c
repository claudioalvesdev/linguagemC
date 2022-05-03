#include <stdio.h>
#include <stdlib.h>

void ordenarVetor(int tamanho, int *vetor);

int buscaBinaria(int *vetor, int valorDesejado, int posicaoInicio, int posicaoFinal);

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
	
	indiceDesejado = buscaBinaria(vetor, valorDesejado, 0, 99);
	
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

int buscaBinaria(int *vetor, int valorDesejado, int posicaoInicio, int posicaoFinal) {
	int posicaoMeio = (posicaoInicio + posicaoFinal) / 2;
	
	if(posicaoInicio > posicaoFinal) {
		return - 1;
	}
	
	if(valorDesejado == vetor[posicaoMeio]) {
		return posicaoMeio;
	}
	
	if(valorDesejado < vetor[posicaoMeio]) {
		return buscaBinaria(vetor, valorDesejado, posicaoInicio, posicaoMeio - 1);
	} else {
		return buscaBinaria(vetor, valorDesejado, posicaoMeio + 1, posicaoFinal);
	} 
	
}
