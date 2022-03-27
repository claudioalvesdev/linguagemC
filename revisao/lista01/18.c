#include <stdio.h>
#include <math.h>
#define PI 3.14

	/*	ALUNO: Antonio Claudio Teixeira Alves
	Implemente uma funcao que calcule a area da superficie e o
	volume de uma esfera de raio R. Essa funcao deve obedecer ao prototipo:*/
	
void separador();

void calcularEsfera(float r, float *a, float *v);

int main() {
	float raio, area, volume;
	
	separador();
	printf("\tAREA E VOLUME DE ESFERA\n");
	separador();
	printf("Raio: ");
	scanf("%f", &raio);
	separador();
	
	calcularEsfera(raio, &area, &volume);
	printf("Area: %.2f\n", area);
	printf("Volume: %.2f", volume);
	
	return 0;
}

void separador() {
	printf("--------------------------------------\n");
}

void calcularEsfera(float r, float *a, float *v) {
	*a = 4 * PI * pow(r, 2);
	*v = 4/3 * PI * pow(r, 3);
}
