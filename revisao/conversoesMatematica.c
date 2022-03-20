#include <stdio.h> 

	/*	ALUNO: Antonio Claudio Teixeira Alves
	Fazer um programa em C que pergunta um valor em metros e 
	imprime ocorrespondente em decímetros, centímetros e milímetros.*/
	
void separador();

int main() {
	float valorEmMetro;
	char condicao;
	
	separador();
	printf("CONVERSOES DE UNIDADE (m)\n");
	separador();
	
	do {
		printf("Valor (m): ");
		scanf("%f", &valorEmMetro);
		separador();
		
		printf("Decimetros: %.2f dm\n", valorEmMetro*10);
		printf("Centimetros: %.2f cm\n", valorEmMetro*100);
		printf("Milimetros: %.2f mm\n", valorEmMetro*1000);
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
