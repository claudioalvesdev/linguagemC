#include <stdio.h>

	/*	ALUNO: Antonio Claudio Teixeira Alves
	Crie uma funcao para somar dois arrays. Esta funcao deve receber dois arrays
	e retornar a soma em um terceiro array. Caso o tamanho do primeiro e segundo array
	seja diferente entao a funcao retornar a ZERO (0). Caso a funcao seja concluida com
	sucesso a mesma deve retornar o valor UM (1). Utilize aritmetica de ponteiros para
	manipulacao do array.*/
	
void separador();

void espaco();

int concatenarVetores(int *vetor1, int *vetor2, int tamanhoV1, int tamanhoV2, int *vetor3);

int main() {
	int tamanhoV1, tamanhoV2, retorno;
	
	printf("Tamanho do primeiro vetor: ");
	scanf("%d", &tamanhoV1);
	printf("Tamanho do segundo vetor: ");
	scanf("%d", &tamanhoV2);
	
	
	int vetor1[tamanhoV1], vetor2[tamanhoV2], vetor3[tamanhoV1];
	
	espaco();
	separador();
	printf("Vetor 1\n");
	for(int i = 0; i < tamanhoV1; i++) {
		printf("Valor %d: ", i + 1);
		scanf("%d", &vetor1[i]);
	}
	
	espaco();
	separador();
	printf("Vetor 2\n");
	for(int i = 0; i < tamanhoV2; i++) {
		printf("Valor %d: ", i + 1);
		scanf("%d", &vetor2[i]);
	}
	
	retorno = concatenarVetores(vetor1, vetor2, tamanhoV1, tamanhoV2, vetor3);
	
	espaco();
	separador();
	if(tamanhoV1 == tamanhoV2) {
		printf("Vetor 3\n");
		for(int i = 0; i < tamanhoV1; i++) {
			printf("[%d] ", vetor3[i]);
		}	
	}
	printf("\nRetorno da funcao: %d", retorno);
	
	return 0;
}

void separador() {
	printf("--------------------------\n");
}

void espaco() {
	printf("\n\n");
}

int concatenarVetores(int *vetor1, int *vetor2, int tamanhoV1, int tamanhoV2, int *vetor3) {
	if(tamanhoV1 == tamanhoV2) {
		for(int i = 0; i < tamanhoV1; i++) {
			*(vetor3 + i) = *(vetor1 + i) + *(vetor2 + i);
		}
		
		return 1;
	} else {
		return 0;
	}
}
