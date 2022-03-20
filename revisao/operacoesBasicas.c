#include <stdio.h> 

	/*	ALUNO: Antonio Claudio Teixeira Alves
	Fazer um programa em "C" que solicite 2 números e informe: 
	a) A soma dos números; b) O produto do primeiro número pelo quadrado do segundo; 
	c) O quadrado do primeiro número*/
	
void separador();

int main() {
	float primeiroValor, segundoValor;
	char condicao;
	
	separador();
	printf("\tOPERACOES BASICAS\n");
	separador();
	do {
		printf("Valor 1: ");
		scanf("%f", &primeiroValor);
		printf("Valor 2: ");
		scanf("%f", &segundoValor);
		separador();
		
		printf("Soma: %.2f\n", primeiroValor + segundoValor);
		printf("O produto do primeiro numero pelo quadrado do segundo: %.2f\n", primeiroValor * segundoValor * segundoValor);
		printf("O quadrado do primeiro numero: %.2f\n", primeiroValor * primeiroValor);
		separador();
		
		printf("Deseja continuar [s / n]: ");
		scanf("%s", &condicao);
		separador();
	} while (condicao != 'n');
	
	printf("Obrigado por usar nosso servico :)\n");
	
	return 0;
}

void separador() {
	printf("----------------------------------\n");
}
