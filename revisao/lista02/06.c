#include <stdio.h>

	/*	ALUNO: Antonio Claudio Teixeira Alves
	Faca um programa que realize a leitura dos seguintes dados relativos
	a um conjunto de alunos: Matricula, Nome, Codigo da Disciplina, Nota1 e 
	Nota2. Considere uma turma de ate 10 alunos. Apos ler todos os dados 
	digitados, e depois de armazena-los em um vetor de estrutura, exibir na 
	tela a listagem final dos alunos com as suas respectivas medias finais
	(use uma media ponderada: Nota1 com peso=1.0 e Nota2 com peso=2.0).*/

struct aluno{
	char matricula[20];
	char nome[80];
	char codigoDisciplima[10];
	float n1, n2;
};

typedef struct aluno Estudantes;

void separador();

int main() {
	Estudantes estudante[10];
	
	separador();
	printf("\tSISTEMA DE ALUNXS\n");
	separador();
	
	for(int i = 0; i < 10; i++) {
		printf("\n\nCadastrar Alunx %d\n", i + 1);
		fflush(stdin);
		printf("Nome: ");
		gets(estudante[i].nome);
		
		fflush(stdin);
		printf("Matricula: ");
		gets(estudante[i].matricula);
		
		fflush(stdin);
		printf("Codigo da Disciplina: ");
		gets(estudante[i].codigoDisciplima);
		
		printf("Nota 01: ");
		scanf("%f", &estudante[i].n1);
		printf("Nota 02: ");
		scanf("%f", &estudante[i].n2);
	}
	
	for(int i = 0; i < 10; i++) {
		printf("\n\nDADO DO ALUNX %d\n", i + 1);
		printf("Nome: %s\n", estudante[i].nome);
		printf("Matricula: %s\n", estudante[i].matricula);
		printf("Codigo da Disciplina: %s\n", estudante[i].codigoDisciplima);
		printf("Nota 01: %.2f\n", estudante[i].n1);
		printf("Nota 02: %.2f\n", estudante[i].n2);
		printf("Media Ponderada: %.2f\n", (estudante[i].n1 + estudante[i].n2*2)/3);
	}
	
	
	return 0;
}

void separador() {
	printf("--------------------------------------\n");
}
