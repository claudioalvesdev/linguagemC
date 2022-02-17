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
Facebook *primeiroUsuario;
int qtdUsuarios = 0;

void separador();

void adicionarUsuarios();

void mostrarUsuarios(Facebook *usuarios);

void procurarUsuariosPorNome(Facebook *usuarios, char nome[]);

void procurarUsuariosPorId(Facebook *usuarios, int id);

void tipoDeRelacao(int amigo1, int amigo2, Facebook *usuarios);

void relacaoDeAmizade(Facebook *usuarios);

void liberar(Facebook *usuarios);

int main() {
	int auxiliar = 0, opcao, procurarPorId, meuId, idDesejado;
	char condicao, procurarPorNome[80];
	
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
		scanf("%d", &opcao);
		
		switch(opcao) {
			
			case 1:
				
				do{
					adicionarUsuarios();	
					printf("Deseja continuar? [s / n]: ");
					scanf("%s", &condicao);
				} while(condicao != 'n');
				
				break;
				
			case 2:
				
				mostrarUsuarios(primeiroUsuario);
				
				break;
				
			case 3:
				
				do{
					separador();
					printf("[1] - Por nome\n");
					printf("[2] - Por id\n");
					printf("[3] - Voltar\n");
					separador();
					printf("Sua opcao: ");
					scanf("%d", &opcao);
					
					switch(opcao) {
						case 1:
							
							fflush(stdin);
							printf("Nome: ");
							gets(procurarPorNome);
							procurarUsuariosPorNome(primeiroUsuario, procurarPorNome);
							
							break;
							
						case 2:
							
							fflush(stdin);
							printf("Id: ");
							scanf("%d", &procurarPorId);
							procurarUsuariosPorId(primeiroUsuario, idDesejado);
							
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
					scanf("%d", &opcao);
					
					switch(opcao) {
						
						case 1:
							
							separador();
							printf("OLA SOU SEU ASSISTENTE VIRTUAL, ZERO.\n");
							printf("PARA COMECAR\n");
							separador();
							printf("Digite seu id: ");
							scanf("%d", &meuId);
							separador();
							printf("Digite o id da pessoa que\ndeseja ser amigo: ");
							scanf("%d", &idDesejado);
							
							if(primeiroUsuario == NULL) {
								printf("[ERROR] Nao existe usuarios cadastrados\n");
							} else{
								separador();
								tipoDeRelacao(meuId, idDesejado, primeiroUsuario);	
								separador();
							}
							
							break;
							
						case 2:
							
							relacaoDeAmizade(primeiroUsuario);
							
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
		
	} while(auxiliar != 1);
	
	liberar(primeiroUsuario);
	
	return 0;
}

void separador() {
	printf("-------------------------------------\n");
}

void adicionarUsuarios() {
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
	
	qtdUsuarios++;
	usuarios->id = qtdUsuarios;
	
	usuarios->prox = NULL;
	if(primeiroUsuario == NULL) {
		primeiroUsuario = usuarios;
	} else{
		Facebook *auxiliarUsuario = primeiroUsuario;
		
		while(auxiliarUsuario->prox != NULL) {
			auxiliarUsuario = auxiliarUsuario->prox;
		}
		
		auxiliarUsuario->prox = usuarios;
	}
}

void mostrarUsuarios(Facebook *usuarios) {
	
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
		
		mostrarUsuarios(usuarios->prox);
	}
	
}

void procurarUsuariosPorNome(Facebook *usuarios, char nome[]) {
	
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
			
		procurarUsuariosPorNome(usuarios->prox, nome);
	}
	
}

void procurarUsuariosPorId(Facebook *usuarios, int id) {
	
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
			
		procurarUsuariosPorId(usuarios->prox, id);
	}
	
}

void tipoDeRelacao(int amigo1, int amigo2, Facebook *usuarios) {
		Facebook *aux = usuarios;
		Facebook *auxAdicionar, *amizade;
		
		while(amigo1 != aux->id) {
			aux = aux->prox;
		}
		
		if(amigo1 == aux->id) {
			auxAdicionar = primeiroUsuario;
			
			while(amigo2 != auxAdicionar->id && auxAdicionar->prox != NULL) {
				auxAdicionar = auxAdicionar->prox;
			}
			
		} 
		
		if(amigo2 == auxAdicionar->id) {
			amizade = aux;
				
			while(amizade->amigos != NULL) {
				amizade = amizade->amigos;
			}
				
			amizade->amigos = auxAdicionar;
			
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
					
					adicionarUsuarios();
					separador();
					tipoDeRelacao(amigo1, amigo2, primeiroUsuario);
					separador();
					
					break;
					
				case 2:
					
					liberar(primeiroUsuario);
					printf("Encerrado programa .....\n");
					exit(0);
					
					break;
					
				default:
					printf("[ERROR] Opcao invalida :x\n");
			}
			
		}
		
		printf("%s adicionou %s na lista de amizade\n", aux->nome, aux->amigos->nome);
}

void relacaoDeAmizade(Facebook *usuarios) {
	
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

