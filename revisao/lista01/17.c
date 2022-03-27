#include <stdio.h>

	/*	ALUNO: Antonio Claudio Teixeira Alves
	Escreva uma funcao que dado um numero real passado como parametro,
	retorne a parte inteira e a parte fracionaria deste numero. Escreva
	um programa que chama esta funcao.*/
	
void fracionado(float n, float *f, int *i);

int main() {
	float numero, fracao;
	int inteiro;
	
	printf("Digite um numero: ");
	scanf("%f", &numero);
	
	fracionado(numero, &fracao, &inteiro);
	
	printf("Numero: %.2f\n", numero);
	printf("Inteiro: %d\n", inteiro);
	printf("Fracionado: %.5f", fracao);
	
	return 0;	
}

void fracionado(float n, float *f, int *i) {
	*i = (int)n;
	*f = n - *i; 
}
