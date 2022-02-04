#include <stdio.h>
#include <stdlib.h>

	/*	ALUNO: Antonio Claudio Teixeira Alves
	O sistema de uma editora utiliza uma lista simplesmente encadeada para armazenar os dados dos
	seus livros. Está lista é automaticamente ordenada crescentemente pelos anos dos livros e cada nó
	da lista é representado pelo tipo estruturado NoDaLista:
	
	struct noDaLista
	{
	char titulo[51];
	char autor[51];
	int ano;
	int quantidade;
	NoDaLista *prox;
	};
	
	Com base nessa definição, implemente as seguintes funções além de incluir e mostrar todos os
	dados: ???
	a) quantidade_livros – a função recebe por parâmetro o endereço do primeiro elemento da lista
	encadeada e deve retornar a quantidade total de livros em estoque (somatório dos campos
	quantidade existentes na estrutura dos nós da lista);
	b) livros_ano – a função recebe por parâmetro o endereço do primeiro elemento da lista encadeada
	e um determinado ano. A função deve exibir na tela os dados de todos os livros existentes na lista
	que foram publicados no ano especificado. Obrigatoriamente a função deve ser implementada de
	forma recursiva;*/
	
struct sistema {
	char titulo[51];
	char autor[51];
	int ano;
	int quantidade;
	struct sistema *prox;
};

typedef struct sistema Editora;
Editora *primeiro;
int qtd_de_livros;	
	
void separador();

void add_livro();

void mostrar_livros(Editora *livros);

int quantidade_livros(Editora *livros);

void livros_ano(Editora *livros, int ano);

void liberar(Editora *livros);
	
int main() {
	int aux = 0, escolha, qtd_livros = 0, ano_pub;
	char condicao = 's';
	
	do{
		separador();
		printf("\tMENU\n");
		separador();
		printf("[1] - Sistema de livros\n");
		printf("[2] - Sair\n");
		separador();
		printf("Opcao: ");
		scanf("%d", &escolha);
		
		switch(escolha) {
			case 1:
				do{
					separador();
					printf("[1] - Inserir livros\n");
					printf("[2] - Listar livros\n");
					printf("[3] - Quantidade de livros\n");
					printf("[4] - Procurar por ano\n");
					printf("[5] - Voltar\n");
					separador();
					printf("Opcao: ");
					scanf("%d", &escolha);
					
					switch(escolha) {
						case 1:	
							condicao = 's';
							while(condicao != 'n'){
								add_livro();
								printf("Deseja continuar? [s / n] : ");
								scanf("%s", &condicao);
							} 
							break;
							
						case 2:	
							mostrar_livros(primeiro);
							break;
						
						case 3:
							qtd_livros = quantidade_livros(primeiro);
							printf("Estoque: %d\n", qtd_livros);
							break;
							
						case 4:
							printf("Ano de publicacao: ");
							scanf("%d", &ano_pub);
							livros_ano(primeiro, ano_pub);
							break;
							
						case 5:
							aux = 2;
							break;
							
						default:
							printf("[ERROR] Opcao Invalida :x\n");
					}
				} while(aux != 2);
				break;
			case 2:
				aux = 1;
				break;
			default:
				printf("[ERRO] Opcao Invalida :x\n");
		}
	} while(aux != 1);
	
	liberar(primeiro);
	
	return 0;
}

void separador() {
	printf("---------------------------\n");
}

void add_livro() {
	Editora *livros = malloc(sizeof(Editora));
	
	separador();
	fflush(stdin);
	printf("Titulo: ");
	gets(livros->titulo);
	
	fflush(stdin);
	printf("Autor: ");
	gets(livros->autor);
	
	fflush(stdin);
	printf("Ano: ");
	scanf("%d", &livros->ano);
	
	fflush(stdin);
	printf("Quantidade: ");
	scanf("%d", &livros->quantidade);
	
	livros->prox = primeiro;
	primeiro = livros;
}

void mostrar_livros(Editora *livros) {
	if(livros != NULL) {
		printf("\n\n");
		separador();
		printf("Titulo: %s\n", livros->titulo);
		printf("Autor: %s\n", livros->autor);
		printf("Ano: %d\n", livros->ano);
		printf("Quantidade: %d\n", livros->quantidade);
		separador();
		printf("\n\n");
		
		mostrar_livros(livros->prox);
	}
}

int quantidade_livros(Editora *livros) {
	if(livros != NULL) {
		qtd_de_livros += livros->quantidade;
		
		quantidade_livros(livros->prox);
	}
	
	return qtd_de_livros;
}

void livros_ano(Editora *livros, int ano) {
	if(livros != NULL) {
		if(livros->ano == ano) {
			printf("\n\n");
			separador();
			printf("Titulo: %s\n", livros->titulo);
			printf("Autor: %s\n", livros->autor);
			printf("Ano: %d\n", livros->ano);
			printf("Quantidade: %d\n", livros->quantidade);
			separador();
			printf("\n\n");
		}
		
		livros_ano(livros->prox, ano);
	}
}

void liberar(Editora *livros) {
	if(livros != NULL) {
		liberar(livros->prox);
		free(livros);
	}
	
}
