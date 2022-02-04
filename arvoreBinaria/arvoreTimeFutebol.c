#include <stdio.h>
#include <stdlib.h>

	/*	ALUNO: Antonio Claudio Teixeira Alves
	Um time de futebol deseja armazenar seu time de uma forma mais otimizada. 
	Para isso, você  foi contratado para criar uma árvore binária para armazenar
	os jogadores titulares desse time. Para isso, cada nó da árvore deve conter
	o número do jogador e o seu nome. Esta árvore deve ser balanceada de acordo
	com o número do jogador. Obs: a árvore não pode conter mais do que 11 jogadores. 
	
	a) Criar uma função para criar um Nó jogador 
	b) Criar uma função para adicionar o jogador na árvore binária 
	c) Imprimir a lista de jogadores em ordem 
	d) Imprimir o jogador Pós-ordem 
	e) Implementar a remoção de um Nó jogador. Ao remover o jogador,
	solicite imediatamente o  jogador que irá substituí-lo. 
	*/
	
struct jogadores {
	int numero_jogador;
	char nome_jogador[80];
	struct jogadores *direita;
	struct jogadores *esquerda;
};

typedef struct jogadores Time;

Time *criar_time(int numero_jogador);

void adicionar_jogadores(Time *jogadores, int numero_jogador);

void mostrar_escalacao_ordem(Time *jogadores);

void mostrar_escalacao_posOrdem(Time *jogadores);

void separador();

void substituir_jogador(Time *jogadores, int numero_jogador);

int main() {
	int numero_jogador, opcao, condicao = 0, contador = 0;
	char escolha;
	Time *primeiro_jogador;
	
	do{
		separador();
		printf("\tSelecao Brasileira\n");
		separador();
		printf("[1] - Escalar time\n");
		printf("[2] - Mostrar o time\n");
		printf("[3] - Substituir jogador(es)\n");
		printf("[4] - Terminar escalacao\n");
		separador();
		printf("Sua opcao: ");
		scanf("%d", &opcao);
		
		switch(opcao) {
			case 1:
				
				do{
					printf("Numero da camisa: ");
					scanf("%d", &numero_jogador);
						
					if(contador == 0) {
						primeiro_jogador = criar_time(numero_jogador);
						contador++;
					} else if(contador <= 10) {
						adicionar_jogadores(primeiro_jogador, numero_jogador);
						contador++;
					} else{
						printf("\n[ERROR] O numero maximo de jogadores em campo e 11.\n\n");
						printf("Deseja substituir qual jogador?\n");
						printf("Numero da camisa: ");
						scanf("%d", &numero_jogador);
						substituir_jogador(primeiro_jogador, numero_jogador);
						printf("Deseja substituir por qual jogador?");
						printf("Numero da camisa: ");
						scanf("%d", &numero_jogador);
						adicionar_jogadores(primeiro_jogador, numero_jogador);
						printf("\nSubstituicao feita com sucesso :)\n");
						contador--;
					}
					
					printf("Deseja continuar [s/ n] : ");
					scanf("%s", &escolha);
					
				} while(escolha != 'n');
				
				break;
				
			case 2:
				
				do {
					separador();
					printf("[1] - Em Ordem\n");
					printf("[2] - Pos Ordem\n");
					printf("[3] - Voltar\n");
					separador();
					printf("Sua opcao: ");
					scanf("%d", &escolha);
					
					switch(escolha) {
						case 1:
							
							if(primeiro_jogador == NULL) {
								printf("[ERROR] Escalacao inexistente :(\n");
							} else {
								printf("\n");
								separador();
								printf("\tTime Titular\n");
								separador();
								mostrar_escalacao_ordem(primeiro_jogador);
								printf("\n");
							}
							
							break;
						case 2:
							
							if(primeiro_jogador == NULL) {
								printf("[ERROR] Escalacao inexistente :(\n");
							} else{
								printf("\n");
								separador();
								printf("\tTime Titular\n");
								separador();
								mostrar_escalacao_posOrdem(primeiro_jogador);
								printf("\n");
							}
							
							break;
							
						case 3:
							
							condicao = 1;
							break;
							
						default:
							printf("[ERROR] Opcao invalida x(\n");
					}
				}while(condicao != 1);
				
				break;
				
			case 3:
				printf("Camisa do jogador: ");
				scanf("%d", &numero_jogador);
				substituir_jogador(primeiro_jogador, numero_jogador);
				break;
				
			case 4:
				condicao = 2;
				break;
				
			default:
				printf("[ERROR] Opcao invalida x(\n");
		}
		
	} while(condicao != 2);
	
	
	return 0;
}

Time *criar_time(int numero_jogador) {
	Time *jogadores = malloc(sizeof(Time));
	
	printf("Nome: ");
	scanf("%s", jogadores->nome_jogador);
	jogadores->numero_jogador = numero_jogador;
	jogadores->direita = NULL;
	jogadores->esquerda = NULL;
	
	return jogadores;
}

void adicionar_jogadores(Time *jogadores, int numero_jogador) {
	
	if(numero_jogador > jogadores->numero_jogador) {
		
		if(jogadores->direita == NULL) {
			jogadores->direita = criar_time(numero_jogador);
		} else {
			adicionar_jogadores(jogadores->direita, numero_jogador);
		}
		
	} else {
		
		if(jogadores->esquerda == NULL) {
			jogadores->esquerda = criar_time(numero_jogador);
		} else{
			adicionar_jogadores(jogadores->esquerda, numero_jogador);
		}
		
	}
	
}

void mostrar_escalacao_ordem(Time *jogadores) {
	
	if(jogadores == NULL) {
		return;
	}
	
	mostrar_escalacao_ordem(jogadores->esquerda);
	printf("%s - %d\n", jogadores->nome_jogador, jogadores->numero_jogador);
	mostrar_escalacao_ordem(jogadores->direita);
}

void mostrar_escalacao_posOrdem(Time *jogadores) {
	
	if(jogadores == NULL) {
		return;
	}
	
	mostrar_escalacao_posOrdem(jogadores->esquerda);
	mostrar_escalacao_posOrdem(jogadores->direita);
	printf("%s - %d\n", jogadores->nome_jogador, jogadores->numero_jogador);
}

void separador() {
	printf("---------------------------------\n");
}

void substituir_jogador(Time *jogadores, int numero_jogador) {
	Time *escalacao_anterior = jogadores;
	Time *nova_escalacao;
	
	do{
		nova_escalacao = escalacao_anterior;
		
		if(numero_jogador > escalacao_anterior->numero_jogador) {
			escalacao_anterior = escalacao_anterior->direita;
		} else if(numero_jogador < escalacao_anterior->numero_jogador) {
			escalacao_anterior = escalacao_anterior->esquerda;
		}
		
	} while(escalacao_anterior != NULL && escalacao_anterior->numero_jogador != numero_jogador);
	
	if(escalacao_anterior != NULL) {
		
		printf("\nJogador de camisa %d sera substituido\n", numero_jogador);
		
		if(escalacao_anterior->esquerda == NULL && escalacao_anterior->direita == NULL) {
			
			if(nova_escalacao->esquerda == escalacao_anterior) {
				nova_escalacao->esquerda = NULL;
			}
			if(nova_escalacao->direita == escalacao_anterior) {
				nova_escalacao->direita = NULL;
			}
			
		}
		
		if(escalacao_anterior->esquerda != NULL && escalacao_anterior->direita == NULL) {
			
			if(nova_escalacao->esquerda == escalacao_anterior) {
				nova_escalacao->esquerda = escalacao_anterior->esquerda;
			}
			if(nova_escalacao->direita == escalacao_anterior) {
				nova_escalacao->direita = escalacao_anterior->esquerda;
			}
			
		}
		
		if(escalacao_anterior->esquerda == NULL && escalacao_anterior->direita != NULL) {
			
			if(nova_escalacao->esquerda == escalacao_anterior) {
				nova_escalacao->esquerda = nova_escalacao->direita;
			}
			if(nova_escalacao->direita == escalacao_anterior) {
				nova_escalacao->direita = nova_escalacao->direita;
			}
			
		}
		
		if(escalacao_anterior->esquerda != NULL && escalacao_anterior->direita != NULL) {
			
			if(escalacao_anterior->esquerda->direita == NULL) {
				escalacao_anterior->numero_jogador = escalacao_anterior->esquerda->numero_jogador;
				escalacao_anterior->esquerda = NULL;
			} else {
				Time *reservas = escalacao_anterior->esquerda;
				Time *titulares = reservas;
				
				while(reservas->direita != NULL) {
					titulares = reservas;
					reservas = reservas->direita;
				}
				
				titulares->direita = NULL;
				escalacao_anterior->numero_jogador = reservas->numero_jogador;
			}
			
		}
		
	} else {
		printf("[ERROR] Jogador de camisa %d nao esta na partida\n", numero_jogador);
	}
}
