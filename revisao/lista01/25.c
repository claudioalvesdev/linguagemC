#include <stdio.h>

	/*	ALUNO: Antonio Claudio Teixeira Alves
	Faca um programa que possua uma funcao para
		• ler 2 notas e retorna-las por parametro (chamar uma funcao dedicada
		a ler 2 notas validas e que devolver os 2 numeros lidos);
		• calcular a media simples e a media ponderada e retorna-las por parametro,
		onde a segunda nota tem peso 2 media ponderada = (n1 + n2 * 2)/3;*/

void lerNotas(float *n1, float *n2);

void media(float *n1, float *n2, float *ms, float *mp);

int main() {
	float nota1, nota2, mediaSimples, mediaPonderada;
	
	lerNotas(&nota1, &nota2);
	
	media(&nota1, &nota2, &mediaSimples, &mediaPonderada);
	
	printf("\nMedia Simples: %.2f\nMedia Ponderada: %.2f\n", mediaSimples, mediaPonderada);
	
	return 0;
}

void lerNotas(float *n1, float *n2) {
	printf("Nota 1: ");
	scanf("%f", n1);
	printf("Nota 2: ");
	scanf("%f", n2);
}

void media(float *n1, float *n2, float *ms, float *mp) {
	*ms = (*n1 + *n2) / 2;
	*mp = (*n1 + *n2*2) / 3;
}
