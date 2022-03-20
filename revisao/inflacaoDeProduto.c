#include <stdio.h>

	/*	ALUNO: Antonio Claudio Teixeira Alves
	Fazer um programa em "C" que lê o preço de um produto e inflaciona esse
	preço em 10% se ele for menor que 100 e em 20% se ele for maior ou igual a 100*/

void separador();

int main() {
	float valorDoProduto, inflacao;
	char condicao;
	
	separador();
	printf("INFLACAO DE MERCADORIA\n");
	separador();
	
	do {
		printf("Valor do produto: ");
		scanf("%f", &valorDoProduto);
		
		if(valorDoProduto < 100) {
			inflacao = (valorDoProduto * 10/100) + valorDoProduto;
		} else {
			inflacao = (valorDoProduto * 20/100) + valorDoProduto;
		}
		
		separador();
		printf("Preco Final: %.2f reais\n", inflacao);
		separador();
		
		printf("Deseja continuar [s/ n]: ");
		scanf("%s", &condicao);
		separador();
	} while(condicao != 'n');
	
	printf("Obrigado por usar nosso servico :)\n");
	
	return 0;
}

void separador() {
	printf("------------------------------\n");
}
