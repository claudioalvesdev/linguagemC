#include <stdio.h>
#include <stdlib.h>

	/*	ALUNO: Antonio Claudio Teixeira Alves
	Considere as declara��es da imagem a seguir para representar o 
	cadastro de alunos de uma disciplina e implemente uma fun��o que
	imprima o n�mero de matr�cula, o nome, a turma e a m�dia de todos os 
	alunos aprovados na disciplina. Assuma que o crit�rio para aprova��o �
	dado pela m�dia das tr�s provas (p1, p2 e p3). Afun��o recebe como par�metros
	os n�meros de alunos e um vetor de ponteiros para os dados dos alunos. 
	Essa fun��o deve obedecer ao prot�tipo: void imprime_aprovados(int n, Aluno** tab);
	
	Considere a declara��o do tipo Aluno do exercicio anterior e implemente uma fun��o
	que tenha como valor de retorno a m�dia final obtida pelos alunos de uma determinada
	turma. A nota final de cada aluno � dada pela m�dia das tr�s provas. A fun��o deve
	obedecer ao prot�tipo: float media_turma(int n, Aluno** tab, char turma);*/

struct aluno {
	char nome[81];
	char matricula[8];
	char turma;
	float p1, p2, p3;
};

typedef struct aluno Aluno;

void separador() {
	printf("----------------------------------\n");
}

void mostrarAprovados(int numeroDeAluno, Aluno **estudante) {
	float media;
	
	for(int i = 0; i < numeroDeAluno; i++) {
		media = (estudante[i].p1 + estudante[i].p2 + estudante[i].p3) / 3;
		if(media >= 7) {
			printf("Nome: %s", estudante[i].nome);
			printf("Matricula: %s", estudante[i].matricula);
			printf("Turma: %s", estudante[i].turma);
			printf("Media: %s", media);
		}
	}
}

int main() {
	Aluno *estudante;
	int quantidade, escolha;
	char condicao;
	
	separador();
	printf("\tCADASTRO DE ALUNOS\n");
	separador();
	
	printf("Deseja cadastrar quantos alunos: ");
	scanf("%d", &quantidade);
	
	estudante = malloc(quantidade*sizeof(Aluno));
	
	for(int i = 0; i < quantidade; i++) {
		fflush(stdin);
		printf("Nome: ");
		gets(estudante[i].nome);
		fflush(stdin);
		printf("Matricula: ");
		gets(estudante[i].matricula);
		fflush(stdin);
		printf("Turma: ");
		scanf("%s", &estudante[i].turma);
		printf("Nota 01: ");
		scanf("%f", &estudante[i].p1);
		printf("Nota 02: ");
		scanf("%f", &estudante[i].p2);
		printf("Nota 03: ");
		scanf("%f", &estudante[i].p3);
	}
	
	do{
		separador();
		printf("[1] Mostrar Todos os Alunos Cadastrados\n");
		printf("[2] Mostrar Estudantes Aprovados\n");
		separador();
		printf("Opcao: ");
		scanf("%d", &escolha);
		
		switch(escolha) {
			
			case 1:
				
				break;
				
			case 2:
				
				if(estudante == NULL) {
					printf("[ERRO] Lista de Estudantes Vazia x(\n");
				} else{
					mostrarAprovados(quantidade, &estudante);	
				}
				
				break;
				
			default:
				printf("[ERRO] Opcao Invalida x(\n");
				
		}
		
		printf("Deseja continuar [s/ n]: ");
		scanf("%s", &condicao);
		separador();
	} while(condicao != 'n');
	
	free(estudante);
	printf("Obrigado por usar nosso servico :)");
	
	return 0;
}
