#include <stdio.h>
#include <stdlib.h>
#include <string.h>

	/*	ALUNO: Antonio Claudio Teixeira Alves
	Você foi contratado pela Google para refazer o Facebook. A sua primeira tarefa é implementar
	uma estrutura de dados para representar as relações de amizade dentro do Facebook. Ou seja, para
	cada pessoa cadastrada você tem que armazenar a sua lista de amigos. Considere que cada pessoa
	no Facebook tem um identificador único que é um número inteiro. a. Declare os tipos necessários
	para a implementação dessa estrutura. b. Escreva um procedimento para cadastrar dois amigos:
	void Relaciona(int Amigo1, int Amigo2, TipoFace* pFace)
	Considere que o Amigo1 já está cadastrado no Facebook, enquanto o Amigo2 pode ou não já estar
	cadastrado.*/
	
struct dados {
	char nome[80];
	char sexo[20];
	char status[25];
	int idade;
	int id;
	struct dados *prox;
	struct dados *amigos;
};

typedef struct dados Facebook;
Facebook *primeiro;
int tamanho = 0;

void separador();

void add_usuarios();

void mostrar_usuarios(Facebook *usuarios);

void procurar_usuarios_nome(Facebook *usuarios, char nome[]);

void procurar_usuarios_id(Facebook *usuarios, int id);

void relacao(int amigo1, int amigo2, Facebook *usuarios);

void relacao_amizade(Facebook *usuarios);

void liberar(Facebook *usuarios);

int main() {
	int auxiliar = 0, escolha, procurar_id, id_seu, id_desejado;
	char condicao = 's', procurar_nome[80];
	
	do{
		separador();
		printf("\tBEM VINDO AO FACEBOOK\n");
		separador();
		printf("[1] - Cadastrar usuario\n");
		printf("[2] - Mostrar todos usuarios\n");
		printf("[3] - Procurar usuario\n");
		printf("[4] - Relacao de amizade\n");
		printf("[5] - Sair\n");
		separador();
		printf("Sua opcao: ");
		scanf("%d", &escolha);
		
		switch(escolha) {
			case 1:
				condicao ='s';
				
				while(condicao != 'n') {
					add_usuarios();
					printf("Deseja continuar? [s / n]: ");
					scanf("%s", &condicao);
				}
				break;
			case 2:
				
				mostrar_usuarios(primeiro);
				break;
			case 3:
				do{
					separador();
					printf("[1] - Por nome\n");
					printf("[2] - Por id\n");
					printf("[3] - Voltar\n");
					separador();
					printf("Sua opcao: ");
					scanf("%d", &escolha);
					
					switch(escolha) {
						case 1:
							
							fflush(stdin);
							printf("Nome: ");
							gets(procurar_nome);
							procurar_usuarios_nome(primeiro, procurar_nome);
							break;
						case 2:
							
							fflush(stdin);
							printf("Id: ");
							scanf("%d", &procurar_id);
							procurar_usuarios_id(primeiro, procurar_id);
							break;
						case 3:
							
							auxiliar = 2;
							break;
						default:
							
							printf("[ERROR] Opcao invalida :x\n");
					}
				} while(auxiliar != 2);
				
				break;
			case 4:
				
				do{
					separador();
					printf("[1] - Adicionar amigo\n");
					printf("[2] - Ver todas as relacoes\n");
					printf("[3] - Voltar\n");
					separador();
					printf("Sua opcao: ");
					scanf("%d", &escolha);
					
					switch(escolha) {
						case 1:
							separador();
							printf("OLA SOU SEU ASSISTENTE VIRTUAL, ZERO.\n");
							printf("PARA COMECAR\n");
							separador();
							printf("Digite seu id: ");
							scanf("%d", &id_seu);
							separador();
							printf("Digite o id da pessoa que\ndeseja ser amigo: ");
							scanf("%d", &id_desejado);
							
							if(primeiro == NULL) {
								printf("[ERROR] Nao existe usuarios cadastrados\n");
							} else{
								separador();
								relacao(id_seu, id_desejado, primeiro);	
								separador();
							}
							break;
						case 2:
							
							relacao_amizade(primeiro);
							break;
						case 3:
							
							auxiliar = 3;
							break;
						default:
							
							printf("[ERROR] Opcao invalida x(\n");
					}
				} while(auxiliar != 3);
				break;
			case 5:
				printf("Obrigado por usar nossos servicos ;)\n");
				auxiliar = 1;
				break;
			default:
				printf("[ERROR] Opcao invalida x(\n");
		}
	}while(auxiliar != 1);
	
	liberar(primeiro);
	
	return 0;
}

void separador() {
	printf("-------------------------------------\n");
}

void add_usuarios() {
	Facebook *usuarios = malloc(sizeof(Facebook));
	
	fflush(stdin);
	printf("Nome: ");
	gets(usuarios->nome);
	
	fflush(stdin);
	printf("Sexo: ");
	gets(usuarios->sexo);
	
	fflush(stdin);
	printf("Estado civil: ");
	gets(usuarios->status);
	
	fflush(stdin);
	printf("Idade: ");
	scanf("%d", &usuarios->idade);
	
	tamanho++;
	usuarios->id = tamanho;
	
	usuarios->prox = NULL;
	if(primeiro == NULL) {
		primeiro = usuarios;
	} else{
		Facebook *auxi = primeiro;
		
		while(auxi->prox != NULL) {
			auxi = auxi->prox;
		}
		
		auxi->prox = usuarios;
	}
}

void mostrar_usuarios(Facebook *usuarios) {
	if(usuarios != NULL) {
		printf("\n\n");
		separador();
		printf("Id: %d\n", usuarios->id);
		printf("Nome: %s\n", usuarios->nome);
		printf("Sexo: %s\n", usuarios->sexo);
		printf("Estado civil: %s\n", usuarios->status);
		printf("Idade: %d\n", usuarios->idade);
		separador();
		printf("\n\n");
		
		mostrar_usuarios(usuarios->prox);
	}
}

void procurar_usuarios_nome(Facebook *usuarios, char nome[]) {
	if(usuarios != NULL) {
		if(strcmp(nome, usuarios->nome) == 0) {
			printf("\n\n");
			separador();
			printf("Id: %d\n", usuarios->id);
			printf("Nome: %s\n", usuarios->nome);
			printf("Sexo: %s\n", usuarios->sexo);
			printf("Estado civil: %s\n", usuarios->status);
			printf("Idade: %d\n", usuarios->idade);
			separador();
			printf("\n\n");
		}
			
		procurar_usuarios_nome(usuarios->prox, nome);
	}
}

void procurar_usuarios_id(Facebook *usuarios, int id) {
	if(usuarios != NULL) {
		if(id == usuarios->id) {
			printf("\n\n");
			separador();
			printf("Id: %d\n", usuarios->id);
			printf("Nome: %s\n", usuarios->nome);
			printf("Sexo: %s\n", usuarios->sexo);
			printf("Estado civil: %s\n", usuarios->status);
			printf("Idade: %d\n", usuarios->idade);
			separador();
			printf("\n\n");
		}
			
		procurar_usuarios_id(usuarios->prox, id);
	}
}

void relacao(int amigo1, int amigo2, Facebook *usuarios) {
		Facebook *aux = usuarios;
		Facebook *aux_add, *amizade;
		
		while(amigo1 != aux->id) {
			aux = aux->prox;
		}
		
		if(amigo1 == aux->id) {
			aux_add = primeiro;
			
			while(amigo2 != aux_add->id && aux_add->prox != NULL) {
				aux_add = aux_add->prox;
			}
			
		} 
		
		if(amigo2 == aux_add->id) {
			amizade = aux;
				
			while(amizade->amigos != NULL) {
				amizade = amizade->amigos;
			}
				
			amizade->amigos = aux_add;
			
		} else {
			int decisao;
			
			printf("[ERROR] Amigo inexistente ou nao encontrado\n");
			printf("Desejar cadastra-lo?\n");
			printf("[1] - Sim\n");
			printf("[2] - Nao\n");
			separador();
			printf("Sua opcao: ");
			scanf("%d", &decisao);
			
			switch(decisao) {
				case 1:
					
					add_usuarios();
					separador();
					relacao(amigo1, amigo2, primeiro);
					separador();
					break;
				case 2:
					
					liberar(primeiro);
					printf("Encerrado programa .....\n");
					exit(0);
					break;
				default:
					
					printf("[ERROR] Opcao invalida :x\n");
			}
		}
		
		printf("%s adicionou %s na lista de amizade\n", aux->nome, aux->amigos->nome);
}

void relacao_amizade(Facebook *usuarios) {
	if(usuarios != NULL) {
		printf("%s - %s\n", usuarios->nome, usuarios->amigos->nome);
		
		usuarios = usuarios->prox;
	}
}

void liberar(Facebook *usuarios) {
	if(usuarios != NULL) {
		
		liberar(usuarios->prox);
		free(usuarios);
	}
}

