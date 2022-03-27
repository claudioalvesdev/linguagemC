#include <stdio.h>

	/*	ALUNO: Antonio Claudio Teixeira Alves
	Considere a seguinte declaracao: int A, *B, **C, ***D; Escreva um programa
	que leia a variavel a e calcule e exiba o dobro, o triplo e o quadruplo desse
	valor utilizando apenas os ponteiros B, C e D. O ponteiro B deve ser usada para
	calcular o dobro, C o triplo e D o quadruplo.*/

int main() {
	int a, *b = &a, **c = &b, ***d = &c;
	
	printf("Digite um valor: ");
	scanf("%d", &a);
	
	printf("\nValor A: %d\n", a);
	printf("Dobro: %d\n", (*b * 2));
	printf("Triplo: %d\n", (**c * 3));
	printf("Quadruplo: %d\n", (***d * 4));
	
	return 0;
}
