#include <stdio.h>

	/*	ALUNO: Antonio Claudio Teixeira Alves
	Escreva um programa que contenha duas variaveis inteiras. 
	Leia essas variaveis do teclado. Em seguida, compare seus
	enderecos e exiba o conteudo do maior endereco.*/
	
void separador();

int main() {
	int valor1, valor2;
	
	separador();
	printf("Digite um numero: ");
	scanf("%d", &valor1);
	printf("Digite outro numero: ");
	scanf("%d", &valor2);
	separador();
	
	printf("Seus enderecos sao: %d %d\n", &valor1, &valor2);
	separador();
	
	if(&valor1 > &valor2) {
		printf("A primeiro valor e maior, valor: %d", &valor1);
	} else {
		printf("O segundo valor e maior, valor: %d", &valor2);
	}
	
	return 0;
}

void separador() {
	printf("---------------------------------\n");
}
