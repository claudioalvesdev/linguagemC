#include <stdio.h>

	/*	ALUNO: Antonio Claudio Teixeira Alves
	Escreva um programa em C que leia 5 valores inteiros e imprima para
	cada um o seu correspondente valor absoluto. Para obter o valor absoluto
	do número utilize a função ABSOLUTA especificada abaixo:*/

void separador();

int absoluto(int valor);

int main() {
	int numero, valorAbsoluto;
	char condicao;
	
	separador();
	printf("\tVALOR ABSOLUTO\n");
	separador();
	
	do{
		printf("Valor: ");
		scanf("%d", &numero);
		
		separador();
		valorAbsoluto = absoluto(numero);
		printf("Valor Absoluto: %d\n", valorAbsoluto);
		separador();
		
		printf("Deseja continuar [s / n]: ");
		scanf("%s", &condicao);
		separador();
	} while(condicao != 'n');
	
	printf("Obrigado por usar nosso servico :)");
	
	return 0;
}

void separador() {
	printf("--------------------------------\n");
}

int absoluto(int valor) {
	
	if(valor < 0) {
		return valor * -1;
	}
	
	return valor;
}
