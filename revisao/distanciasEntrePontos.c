#include <stdio.h>
#include <math.h>

	/*	ALUNO: Antonio Claudio Teixeira Alves
	Escreva uma  função que calcule e retorne a distância entre dois pontos 
	(x1, x2) e (y1, y2). Todos os números e valores de retorno devem ser do tipo float.*/

void separador();

float distanciaEntrePontos(float x1, float x2, float y1, float y2);

int main() {
	float x1, x2, y1, y2, distancia;
	char condicao;
	
	separador();
	printf("DISTANCIAS ENTRE PONTOS\n");
	separador();
	
	do {	
		printf("x1: ");
		scanf("%f", &x1);
		printf("x2: ");
		scanf("%f", &x2);
		printf("y1: ");
		scanf("%f", &y1);
		printf("y2: ");
		scanf("%f", &y2);
		
		distancia = distanciaEntrePontos(x1, x2, y1, y2);
		separador();
		printf("Distancia de: %.2f\n", distancia);
		separador();
		
		printf("Deseja continuar [s/ n]: ");
		scanf("%s", &condicao);
		
	} while(condicao != 'n');
	
	separador();
	printf("Obrigado por usar nosso servico :)\n");
	
	return 0;
}

void separador() {
	printf("------------------------------\n");
}

float distanciaEntrePontos(float x1, float x2, float y1, float y2) {
	return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}
