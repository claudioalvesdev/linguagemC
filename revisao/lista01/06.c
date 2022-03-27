#include <stdio.h>

	/*	ALUNO: Antonio Claudio Teixeira Alves
	Elaborar um programa que leia dois valores inteiros (A e B).
	Em seguida faca uma funcao que retorne a soma do dobro dos dois
	numeros lidos. A funcao dever a armazenar o dobro de A na propria variavel
	A e o dobro de B na propria variavel B.*/

void separador();

int somaValores(int *valorA, int *valorB);

int main() {
	int numeroA, numeroB, soma;
	
	printf("Digite um valor: ");
	scanf("%d", &numeroA);
	printf("Digite outro valor: ");
	scanf("%d", &numeroB);
	
	separador();
	printf("Valor A: %d\n", numeroA);
	printf("Valor B: %d\n", numeroB);
	
	soma = somaValores(&numeroA, &numeroB);
	
	separador();
	printf("Valor A: %d\n", numeroA);
	printf("Valor B: %d\n", numeroB);
	printf("Dobro (A + B): %d\n", soma);
	separador();
	
	return 0;
}

void separador() {
	printf("--------------------------------\n");
}

int somaValores(int *valorA, int *valorB) {
	*valorA *= 2;
	*valorB *= 2;
	
	return (*valorA + *valorB)*2;
}
