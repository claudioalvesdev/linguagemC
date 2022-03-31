#include <stdio.h>
	
	/*	ALUNO: Antonio Claudio Teixeira Alves
	Crie uma estrutura representando os alunos de um determinado curso. A estrutura deve
	conter a matricula do aluno, nome, nota da primeira prova, nota da segunda prova e nota
	da terceira prova.
		(a) Permita ao usuario entrar com os dados de 5 alunos. 
		(b) Encontre o aluno com maior nota da primeira prova.
		(c) Encontre o aluno com maior media geral.
		(d) Encontre o aluno com menor media geral.
		(e) Para cada aluno diga se ele foi aprovado ou reprovado, considerando o valor 6 para
		aprovacao.*/

struct aluno {
	char matricula[20];
	char nome[80];
	float n1, n2, n3;
};

typedef struct aluno Aluno;

void separador();

int main() {
	Aluno estudantes[5];
	float maiorNotaN1, maiorMedia, menorMedia;
	
	separador();
	printf("CADASTRO DE ESTUDANTES\n");
	separador();
	
	for(int i = 0; i < 5; i++) {
		printf("\n\nESTUDANTE %d\n", i + 1);
		
		fflush(stdin);
		printf("Nome: ");
		gets(estudantes[i].nome);
		
		fflush(stdin);
		printf("Matricula: ");
		gets(estudantes[i].matricula);
		
		fflush(stdin);
		printf("Nota 1: ");
		scanf("%f", &estudantes[i].n1);
		
		printf("Nota 2: ");		
		scanf("%f", &estudantes[i].n2);
		
		printf("Nota 3: ");
		scanf("%f", &estudantes[i].n3);
	}
	
	for(int i = 0; i < 5; i++) {
		
		if(i == 0) {
			maiorNotaN1 = estudantes[0].n1;
			maiorMedia = (estudantes[0].n1 + estudantes[0].n2 + estudantes[0].n3) / 3;
			menorMedia = (estudantes[0].n1 + estudantes[0].n2 + estudantes[0].n3) / 3;
		}
		
		if(estudantes[i].n1 > maiorNotaN1) {
			maiorNotaN1 = estudantes[i].n1;
		}
		
		if((estudantes[i].n1 + estudantes[i].n2 + estudantes[i].n3)/3 > maiorMedia) {
			maiorMedia = (estudantes[i].n1 + estudantes[i].n2 + estudantes[i].n3)/3;
		}
		
		if((estudantes[i].n1 + estudantes[i].n2 + estudantes[i].n3)/3 < menorMedia) {
			menorMedia = (estudantes[i].n1 + estudantes[i].n2 + estudantes[i].n3)/3;
		}
	}
	
	for(int i = 0; i < 5; i++) {
		printf("\n\nDADOS DO(A) ESTUDANTE %d\n", i + 1);
		printf("Nome: %s\n", estudantes[i].nome);
		printf("Matricula: %s\n", estudantes[i].matricula);
		printf("Nota 01: %.2f\n", estudantes[i].n1);
		printf("Nota 02: %.2f\n", estudantes[i].n2);
		printf("Nota 03: %.2f\n", estudantes[i].n3);
		printf("Media: %.2f\n", (estudantes[i].n1 + estudantes[i].n2 + estudantes[i].n3)/3);
		printf("Situacao: ");
		if((estudantes[i].n1 + estudantes[i].n2 + estudantes[i].n3)/3 >= 6) {
			printf("APROVADO\n");
		} else{
			printf("REPROVADO\n");
		}
	}
	
	printf("\n\nMaior nota n1: %.2f\n", maiorNotaN1);
	printf("Maior Media: %.2f\n", maiorMedia);
	printf("Menor Media: %.2f\n", menorMedia);
	
	
	return 0;
}

void separador() {
	printf("--------------------------\n");
}
