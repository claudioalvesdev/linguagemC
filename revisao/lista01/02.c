#include <stdio.h>

	/*	ALUNO: Antonio Claudio Teixeira Alves
  	Escreva um programa que contenha duas variaveis inteiras
  	Compare seus enderecos e exiba o maior endereco*/

int main() {
	int var1, var2;
	
	printf("Variavel 1: %d\nVariavel 2: %d\n\n", &var1, &var2);
	
	if(&var1 > &var2) {
		printf("A variavel 1 e maior, seu valor e: %d", &var1);
	} else if(&var2 > &var1) {
		printf("A Variavel 2 e maior, com valor de: %d", &var2);
	} else{
		printf("As variaveis sao iguais, valor: %d", &var1);
	}
	
	return 0;
}
