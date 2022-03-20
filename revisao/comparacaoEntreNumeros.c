#include <stdio.h>

	/*	ALUNO: Antonio Claudio Teixeira Alves
	Faça um programa em "C" que lê dois valores e imprime: 
	- se o primeiro valor for menor que o segundo, a lista de valores do primeiro até o segundo; 
	- se o primeiro valor for maior que o segundo a lista de valores do primeiro até o segundo em ordem decrescente; 
	- se ambos forem iguais a mensagem "valores iguais".*/
	
void separador();

int main() {
	int primeiroNumero, segundoNumero;
	char condicao;
	
	separador();
	printf("COMPARADOR DE NUMEROS\n");
	separador();
	
	do {
		printf("Primeiro Valor: ");
		scanf("%d", &primeiroNumero);
		printf("Segundo Valor: ");
		scanf("%d", &segundoNumero);
		separador();
		
		if(primeiroNumero < segundoNumero) {
			for(int i = primeiroNumero; i <= segundoNumero; i++) {
				printf("%d ", i);
			}
		} else if (primeiroNumero > segundoNumero) {
			for(int i = primeiroNumero; i >= segundoNumero; i--) {
				printf("%d ", i);
			}
		} else {
			printf("Valores iguais");
		}
		printf("\n");
		
		separador();
		printf("Deseja continuar [s/ n]: ");
		scanf("%s", &condicao);
		separador();	
	} while(condicao != 'n');
	
	printf("Obrigado por usar nosso servico :)\n");
	
	return 0;
}

void separador() {
	printf("------------------------------------\n");
}
