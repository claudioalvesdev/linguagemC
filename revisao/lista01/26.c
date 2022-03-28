#include <stdio.h>
#include <math.h>

	/*	ALUNO: Antonio Claudio Teixeira Alves
	Implemente uma funcao que calcule as raizes de uma equacao
	do segundo grau do tipo Ax^2 + Bx + C = 0. Lembrando que:
	Essa funcao deve ter como valor de retorno o numero de raizes
	reais e distintas da equacao. Se existirem raizes reais, seus
	valores devem ser armazenados nas variaveis apontadas por X1 e X2.*/

void separador();

int raizes(float a, float b, float c, float *x1, float *x2);

int main() {
	float a, b, c, x1, x2;
	int qtdDeRaizes;
	
	separador();
	printf("RAIZES DE UMA EQUACAO\n");
	separador();
	printf("Valor de A: ");
	scanf("%f", &a);
	printf("Valor de B: ");
	scanf("%f", &b);
	printf("Valor de C: ");
	scanf("%f", &c);
	separador();
	printf("Funcao do tipo: \n%.2fx^2 + %.2fx + %.2f = 0\n", a, b, c);
	separador();
	
	qtdDeRaizes = raizes(a, b, c, &x1, &x2);
	
	printf("Raizes possiveis: [%d]\n", qtdDeRaizes);
	if(qtdDeRaizes == 0) {
		printf("[ERRO] Nao existe raizes negativos no campo dos reais\n");
	} else {
		printf("X1: %.2f\n", x1);
		printf("X2: %.2f\n", x2);
	}
	
	return 0;
}

void separador() {
	printf("---------------------------\n");
}

int raizes(float a, float b, float c, float *x1, float *x2) {
	float delta;
	
	delta = pow(b, 2) - 4 * a *c;
	
	if(delta < 0) {
		return 0;
	} else if(delta == 0) {
		*x1 = (-b + sqrt(delta)) / (2*a);
		return 1;
	} else if(delta > 0){
		*x1 = (-b + sqrt(delta)) / (2*a);
		*x2 = (-b - sqrt(delta)) / (2*a);
		return 2;
	}
}
