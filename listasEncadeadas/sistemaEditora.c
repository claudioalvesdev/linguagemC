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
Editora *primeiroLivro;
int qtdDeLivros = 0;	
	
void separador();

void adicionarLivros();

void mostrarLivros(Editora *livros);

int quantidadeLivros(Editora *livros);

void anoLivros(Editora *livros, int ano);

void liberar(Editora *livros);
	
int main() {
	int auxiliar = 0, opcao, qtdLivros = 0, anoPublicacao;
	char condicao;
	
	do{
		separador();
		printf("\tMENU\n");
		separador();
		printf("[1] - Sistema de livros\n");
		printf("[2] - Sair\n");
		separador();
		printf("Opcao: ");
		scanf("%d", &opcao);
		
		switch(opcao) {
			
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
					scanf("%d", &opcao);
					
					switch(opcao) {
						
						case 1:	
						
							do{
								adicionarLivros();
								printf("Deseja continuar? [s / n] : ");
								scanf("%s", &condicao);
							} while(condicao != 'n');
	
							break;
							
						case 2:
							
							if(primeiroLivro == NULL) {
								printf("\nLista de livros ainda esta vazio :/\n");
							} else {
								mostrarLivros(primeiroLivro);	
							}
							
							break;
						
						case 3:
							
							qtdLivros = quantidadeLivros(primeiroLivro);
							printf("Estoque: %d\n", qtdLivros);
							
							break;
							
						case 4:
							
							printf("Ano de publicacao: ");
							scanf("%d", &anoPublicacao);
							anoLivros(primeiroLivro, anoPublicacao);	
							
							break;
							
						case 5:
							
							auxiliar = 2;
							
							break;
							
						default:
							
							printf("[ERROR] Opcao Invalida :(\n");
					}
					
				} while(auxiliar != 2);
				
				break;
				
			case 2:
				
				auxiliar = 1;
				
				break;
				
			default:
				
				printf("[ERROR] Opcao Invalida :(\n");
		}
		
	} while(auxiliar != 1);
	
	printf("\nObrigado por usar nosso sistema ;)\n");
	
	liberar(primeiroLivro);
	
	return 0;
}

void separador() {
	printf("---------------------------\n");
}

void adicionarLivros() {
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
	
	livros->prox = primeiroLivro;
	primeiroLivro = livros;
}

void mostrarLivros(Editora *livros) {
	
	if(livros != NULL) {
		printf("\n\n");
		separador();
		printf("Titulo: %s\n", livros->titulo);
		printf("Autor: %s\n", livros->autor);
		printf("Ano: %d\n", livros->ano);
		printf("Quantidade: %d\n", livros->quantidade);
		separador();
		printf("\n\n");
		
		mostrarLivros(livros->prox);
	}
	
}

int quantidadeLivros(Editora *livros) {
	
	if(livros != NULL) {
		qtdDeLivros += livros->quantidade;
		
		quantidadeLivros(livros->prox);
	}
	
	return qtdDeLivros;
}

void anoLivros(Editora *livros, int ano) {
	
	if(livros != NULL) {
		
		if(livros->ano == ano) {
			printf("\n");
			separador();
			printf("Titulo: %s\n", livros->titulo);
			printf("Autor: %s\n", livros->autor);
			printf("Ano: %d\n", livros->ano);
			printf("Quantidade: %d\n", livros->quantidade);
			separador();
			printf("\n");
		} 
		
		anoLivros(livros->prox, ano);
	}
}

void liberar(Editora *livros) {
	
	if(livros != NULL) {
		liberar(livros->prox);
		free(livros);
	}
	
}
