#include <stdio.h>

	/*	ALUNO: Antonio Claudio Teixeira Alves
	Crie um programa que contenha uma funcao que permita passar
	por parametro dois numeros inteiros A e B. A funcao dever a calcular
	a soma entre estes dois numeros e armazenar o resultado na variavel A.
	Esta funcao nao dever a possuir retorno, mas dever a modificar o valor
	do primeiro parametro. Imprima os valores de A e B na funcao principal.*/

void separador();

void soma(int *valorA, int *valorB);

int main() {
	int numeroA, numeroB;
	
	printf("Digite o valor de A: ");
	scanf("%d", &numeroA);
	printf("Digite o valor de B: ");
	scanf("%d", &numeroB);
	
	separador();
	printf("\tANTES DA MODIFICACAO\n");
	printf("Valor A: %d\n", numeroA);
	printf("Valor B: %d\n", numeroB);
	separador();
	
	soma(&numeroA, &numeroB);
	
	printf("\tDEPOIS DA MODIFICACAO\n");
	printf("Valor A: %d\n", numeroA);
	printf("Valor B: %d\n", numeroB);
	separador();
	
	return 0;
}

void separador() {
	printf("--------------------------------\n");
}

void soma(int *valorA, int *valorB) {
	*valorA += *valorB;
}
