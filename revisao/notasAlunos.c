#include <stdio.h>

	/*	ALUNO: Antonio Claudio Teixeira Alves
	Escreva uma função que receba 3 notas de um aluno e uma letra. Se a
	letra for A a função retorna a média aritmética das notas do aluno, se for
	P, a sua média ponderada (pesos: 5, 3 e 2) e se for H, a sua média harmônica.*/

void separador();

float mediaDasNotas(float notas[3], char tipoDeMedia);

int main() {
	float notas[3], media;
	char condicao, tipoDeMedia;
	
	separador();
	printf("\tNOTAS ALUNOS\n");
	separador();
	
	do {
		
		for(int i = 0; i < 3; i++) {
			printf("Nota %d: ", i+1);
			scanf("%f", &notas[i]);
		}
		
		separador();
		printf("Media Aritmetica (a) || Ponderada (p) || Harmonica (h): ");
		scanf("%s", &tipoDeMedia);
		separador();
		
		media = mediaDasNotas(notas, tipoDeMedia);
		
		if(tipoDeMedia == 'a') {
			printf("Media Aritmetica: %.2f\n", media);
		} else if(tipoDeMedia == 'p') {
			printf("Media Ponderada: %.2f\n", media);
		} else if(tipoDeMedia == 'h') {
			printf("Media Harmonica: %.2f\n", media);
		} 
		separador();
		
		printf("Deseja continuar [s / n]: ");
		scanf("%s", &condicao);
		separador();
	} while(condicao != 'n');
	
	printf("Obrigado por usar nosso servico :)");
	
	return 0;
}

void separador() {
	printf("------------------------------\n");
}

float mediaDasNotas(float notas[3], char tipoDeMedia) {
	int soma = 0;
	
	
	
	switch(tipoDeMedia) {
		
		case 'a':
			
			for(int i = 0; i < 3; i++) {
				soma += notas[i];
			}	
			
			return soma/3;
			
			break;
			
		case 'p':
			
			return (notas[0]*5 + notas[1]*3 + notas[2]*2)/10;
			
			break;
			
		case 'h':
			
			return 3 / (1/notas[0] + 1/notas[1] + 1/notas[2]);
			
			break;
			
		default:
			printf("[ERRO] Opcao inexistente x(\n");
	}
}
