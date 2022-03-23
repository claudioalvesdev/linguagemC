#include <stdio.h>
#include <math.h>

	/*Escreva uma função que calcule e retorne a distância entre dois pontos (x1,y1) e (x2,y2).
	Armazene os valores em uma struct*/
	
struct ordenacao {
	float x1, x2, y1, y2;
};

typedef struct ordenacao Valores;

void separador();

float distanciaEntrePontos(Valores ordenacoes);

int main() {
	Valores ordenacoes;
	char condicao;
	float distancia;
	
	separador();
	printf("DISTANCIA ENTRE NUMEROS\n");
	separador();
	
	do {
		printf("x1: ");
		scanf("%f", &ordenacoes.x1);
		printf("y1: ");
		scanf("%f", &ordenacoes.y1);
		printf("x2: ");
		scanf("%f", &ordenacoes.x2);
		printf("y2: ");
		scanf("%f", &ordenacoes.y2);
		
		distancia = distanciaEntrePontos(ordenacoes);
		separador();
		printf("Distancia de: %.2f\n", distancia);
		separador();
		
		printf("Deseja continuar [s/ n]: ");
		scanf("%s", &condicao);
		separador();
	} while(condicao != 'n');
	
	printf("Obrigado por usar nosso servico :)\n");
	
	return 0;
}

void separador() {
	printf("----------------------------\n");
}

float distanciaEntrePontos(Valores ordenacoes) {
	return sqrt(pow((ordenacoes.x2 - ordenacoes.x1), 2) + pow((ordenacoes.y2 - ordenacoes.y1), 2));
}
