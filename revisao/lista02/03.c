#include <stdio.h>
	
	/*	ALUNO: Antonio Claudio Teixeira Alves
	Construa uma estrutura aluno com nome, numero de matricula e curso.
	Leia do usuario a informacao de 5 alunos, armazene em vetor dessa 
	estrutura e imprima os dados na tela.*/
	
struct aluno{
	char nome[80];
	char matricula[15];
	char curso[30];
};

typedef struct aluno Aluno;

int main() {
	Aluno estudante[5];
	
	for(int i = 0; i < 5; i++) {
		printf("DADOS DO(A) ALUNO(A) %d\n", i + 1);
		
		fflush(stdin);
		printf("Nome: ");	
		gets(estudante[i].nome);
		
		fflush(stdin);
		printf("Matricula: ");
		gets(estudante[i].matricula);
		
		fflush(stdin);
		printf("Curso: ");
		gets(estudante[i].curso);
		
		printf("\n\n");
	}
	
	for(int i = 0; i < 5; i++) {
		printf("\tDADO DO ESTUDANTE %d\n", i + 1);
		printf("Nome: %s\n", estudante[i].nome);
		printf("Matricula: %s\n", estudante[i].matricula);
		printf("Curso: %s\n\n\n", estudante[i].curso);
	}
	
	return 0;
}
