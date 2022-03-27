#include <stdio.h>

	/*	ALUNO: Antonio Claudio Teixeira Alves
	Faca um programa que leia 2 valores inteiros e chame
	uma funcao que receba estas 2 variaveis e troque o seu
	conteudo, ou seja, esta funcao e chamada passando duas
	variaveis A e B por exemplo e, apos a execucao da funcao, 
	A conter a o valor de B e B tera o valor de A.*/

void trocarVariavel(int *valorA, int *valorB);
 
int main() {
	int valorA = 2, valorB = 7;
	
	printf("ANTES DA TROCA\n");
	printf("Valor A: %d\n", valorA);
	printf("Valor B: %d\n\n\n", valorB);
	
	trocarVariavel(&valorA, &valorB);
	
	printf("DEPOIS DA TROCA\n");
	printf("Valor A: %d\n", valorA);
	printf("Valor B: %d\n\n\n", valorB);
	
	return 0;
}

void trocarVariavel(int *valorA, int *valorB) {
	int auxA = *valorA;
	
	*valorA = *valorB;
	*valorB = auxA;
}
