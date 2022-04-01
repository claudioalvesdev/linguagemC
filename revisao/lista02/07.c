#include <stdio.h>
#include <math.h>

	/*	ALUNO: Antonio Claudio Teixeira Alves
	Faca um programa que converta coordenadas polares para cartesianas:
		• Crie e leia um ponto em coordenada polar, composto por raio (r) e argumento (a)
		em radianos.
		• Crie outro ponto, agora em coordenada cartesiana, composto por x e y, sabendo
		que x = r * cosa e y = r * sina.
	No programa principal, leia um ponto em coordenada polar e mostre as coordenadas do
	ponto gerado no plano cartesiano.*/

struct coordenadas {
	float raio, argumento;
};

typedef struct coordenadas CoordenadasP;

struct cartesiano {
	float x, y;
};

typedef struct cartesiano CoordenadasC;

void separador();

int main() {
	CoordenadasP ponto;
	CoordenadasC conversao;
	
	separador();
	printf("CONVERTOR DE POLAR PARA CARTESIANO\n");
	separador();
	printf("Raio: ");
	scanf("%f", &ponto.raio);
	printf("Argumento (graus): ");
	scanf("%f", &ponto.argumento);
	printf("\n\n");
	printf("Convertendo...\n");
	printf("\nConversao feita com sucesso!!!\n");
	conversao.x = ponto.raio * cos(ponto.argumento * 0.0174533);
	conversao.y = ponto.raio * sin(ponto.argumento * 0.0174533);
	printf("(x, y) : (%.2f, %.2f)\n", conversao.x, conversao.y);
	
	return 0;
}

void separador() {
	printf("--------------------------------\n");
}
