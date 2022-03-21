#include <stdio.h>
	
	/*	ALUNO: Antonio Claudio Teixeira Alves
	Escreva um programa que leia 5 números inteiros positivos (utilize uma função
	que leia esse número informado escrever a soma de seus divisores (exceto ele mesmo).
	Nome: SomaDivisores
	Descrição: Calcula a soma dos divisores do número informado (exceto ele mesmo).
	Entrada: Um número inteiro e positivo.
	Saída: A soma dos divisores.
	Exemplo: Para o valor 8: 1 + 2 + 4 = 7*/

void separador();

void somaDivisores(int numero);

int main() {
	int numero;
	char condicao;
	
	separador();
	printf("SOMA DE DIVISORES\n");
	separador();
	
	do{
		printf("Numero: ");
		scanf("%d", &numero);
		
		separador();
		somaDivisores(numero);
		separador();
		
		printf("Deseja continuar [s/ n]: ");
		scanf("%s", &condicao);
		separador();
	} while(condicao != 'n');
	
	printf("Obrigado por usar nosso servico :)\n");
	
	return 0;
}

void separador() {
	printf("-----------------------\n");
}

void somaDivisores(int numero) {
	int soma = 0;
	
	printf("Divisores de %d: ", numero);
	for(int i = 1; i < numero; i++) {
		if(numero % i == 0) {
			printf("%d ", i);
			soma += i;
		}
	}
	
	printf(" = %d\n", soma);
}

