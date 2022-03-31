#include <stdio.h>

	/*	ALUNO: Antonio Claudio Teixeira Alves
	
	Considerando a estrutura
	struct Vetor{
	float x;
	float y;
	float z;
	};
	
	para representar um vetor no R3, implemente um programa
	que calcule a soma de dois vetores.*/

struct vetor{
	float x, y, z;
};

typedef struct vetor Vetor;

void separador();

int main() {
	Vetor v[2], resultado;
	
	separador();
	printf("CALCULAR DISTANCIA NO R3\n");
	separador();
	
	for(int i = 0; i < 2; i++) {
		printf("Coordenadas V%d\n", i + 1);
		printf("X: ");
		scanf("%f", &v[i].x);	
		printf("Y: ");
		scanf("%f", &v[i].y);
		printf("Z: ");
		scanf("%f", &v[i].z);
	}
	
	resultado.x = v[0].x + v[1].x;
	resultado.y = v[0].y + v[1].y;
	resultado.z = v[0].z + v[1].z;
	
	printf("\nV1 + V2 = (%.2f, %.2f, %.2f)\n", resultado.x, resultado.y, resultado.z);
	
	return 0;
}

void separador() {
	printf("-----------------------------\n");
}
