#include <stdio.h>
#include <stdlib.h>
#include <string.h>

	/*	ALUNO: Antonio Claudio Teixeira Alves
	Considere as declarações da imagem a seguir para representar o 
	cadastro de alunos de uma disciplina e implemente uma função que
	imprima o número de matrícula, o nome, a turma e a média de todos os 
	alunos aprovados na disciplina. Assuma que o critério para aprovação é
	dado pela média das três provas (p1, p2 e p3). A função recebe como parâmetros
	os números de alunos e um vetor de ponteiros para os dados dos alunos. 
	Essa função deve obedecer ao protótipo: void imprime_aprovados(int n, Aluno** tab);*/

struct aluno {
	char nome[81];
	char matricula[8];
	char turma[1];
	float p1, p2, p3;
};

typedef struct aluno Aluno;

void separador() {
	printf("----------------------------------\n");
}

void iniciarStruct(int numeroDeAluno, Aluno **tabela){
	for(int i = 0; i < numeroDeAluno; i++) {
		tabela[i] = NULL;
	}
}

void cadastrarAluno(int numeroDeAluno, Aluno **tabela, int indiceDoAluno) {
	if(indiceDoAluno < 0 || indiceDoAluno > numeroDeAluno) {
		printf("[ERRO] Indice de aluno inexistente\n");
		exit(1);
	}
	
	if(tabela[indiceDoAluno] == NULL) {
		tabela[indiceDoAluno] = malloc(sizeof(Aluno));
	}
	
	
	printf("\tCadastro do Aluno %d\n", indiceDoAluno);
	separador();
	fflush(stdin);
	printf("Nome: ");
	gets(tabela[indiceDoAluno]->nome);
	fflush(stdin);
	printf("Matricula: ");
	gets(tabela[indiceDoAluno]->matricula);
	fflush(stdin);
	printf("Turma: ");
	gets(tabela[indiceDoAluno]->turma);
	printf("Nota 01: ");
	scanf("%f", &tabela[indiceDoAluno]->p1);
	printf("Nota 02: ");
	scanf("%f", &tabela[indiceDoAluno]->p2);
	printf("Nota 03: ");
	scanf("%f", &tabela[indiceDoAluno]->p3);
	
	printf("Cadastro feito com sucesso :)\n");
}

void removerAlunos(int numeroDeAluno, Aluno **tabela, int indiceDoAluno) {
	if(indiceDoAluno < 0 || indiceDoAluno >= numeroDeAluno) {
		printf("[ERRO] Indice invalido x(\n");
		exit(1);
	}
	
	if(tabela[indiceDoAluno] != NULL) {
		free(tabela[indiceDoAluno]);
		tabela[indiceDoAluno] == NULL;
		
		printf("Aluno removido com sucesso :)\n");
	}
}

void mostrarAlunos(int numeroDeAluno, Aluno **tabela, int indiceDoAluno) {
	if(indiceDoAluno < 0 || indiceDoAluno >= numeroDeAluno) {
		printf("[ERRO] Indice invalido x(\n");
		exit(1);
	}
	
	if(tabela[indiceDoAluno] != NULL) {
		printf("#Dados do Aluno %d", indiceDoAluno + 1);
		printf("Nome: %s", tabela[indiceDoAluno]->nome);
		printf("Matricula: %s", tabela[indiceDoAluno]->matricula);
		printf("Turma: %s", tabela[indiceDoAluno]->turma);
		printf("Nota 01: %f", tabela[indiceDoAluno]->p1);
		printf("Nota 02: %f", tabela[indiceDoAluno]->p2);
		printf("Nota 03: %f", tabela[indiceDoAluno]->p3);
	}
}

void mostrarTodosOsAlunos(int numeroDeAluno, Aluno **tabela) {
	for(int i = 0; i < numeroDeAluno; i++) {
		mostrarAlunos(numeroDeAluno, tabela, i);
	}
}

int main() {
	int quantidade, escolha, indice, opcao;
	char condicao;
	
	separador();
	printf("\tCADASTRO DE ALUNOS\n");
	separador();
	
	printf("Deseja cadastrar quantos alunos: ");
	scanf("%d", &quantidade);
	Aluno *estudante[quantidade];
	
	iniciarStruct(quantidade, estudante);
	
	
	do{
		separador();
		printf("[1] Inserir Aluno\n");
		printf("[2] Mostrar Alunos\n");
		printf("[3] Visualizar Alunos Aprovados\n");
		printf("[4] Remover Aluno\n");
		printf("[5] Sair\n");
		separador();
		printf("Opcao: ");
		scanf("%d", &escolha);
		separador();
		
		switch(escolha) {
			
			case 1:
				
				printf("Indice do Aluno: ");
				scanf("%d", &indice);
				separador();
				cadastrarAluno(quantidade, estudante, indice);
				separador();		
				
				break;
				
			case 2:
				
				mostrarTodosOsAlunos(quantidade,estudante);
				
				break;
				
			case 3:
				
				break;
			
			case 4:
				
				do {
					printf("Indique na qual deseja remover: ");
					scanf("%d", &indice);
					separador();
					removerAlunos(quantidade, estudante, indice);
					
					separador();
					printf("Deseja continuar [s / n]: ");
					scanf("%s", &condicao);
				} while(condicao != 'n');
				
				condicao = 's';
				break;
				
			case 5:
				
				opcao = 1;
				
				break;
				
			default:
				printf("[ERRO] Opcao Invalida x(\n");
				
		}

	} while(opcao != 1);
	
	printf("Obrigado por usar nosso servico :)");
	
	return 0;
}
