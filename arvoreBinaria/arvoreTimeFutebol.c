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
	int numeroJogador;
	char nomeJogador[80];
	struct jogadores *direita;
	struct jogadores *esquerda;
};

typedef struct jogadores Time;

Time *criarTime(int numeroJogador);

void adicionarJogadores(Time *jogadores, int numeroJogador);

void mostrarEscalacaoOrdem(Time *jogadores);

void mostrarEscalacaoPosOrdem(Time *jogadores);

void separador();

void substituirJogador(Time *jogadores, int numeroJogador);

int main() {
	int numeroJogador, opcao, condicao = 0, contador = 0;
	char escolha;
	Time *primeiroJogador;
	
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
					scanf("%d", &numeroJogador);
						
					if(contador == 0) {
						primeiroJogador = criarTime(numeroJogador);
						contador++;
					} else if(contador <= 10) {
						adicionarJogadores(primeiroJogador, numeroJogador);
						contador++;
					} else{
						printf("\n[ERROR] O numero maximo de jogadores em campo e 11.\n\n");
						printf("Deseja substituir qual jogador?\n");
						printf("Numero da camisa: ");
						scanf("%d", &numeroJogador);
						substituirJogador(primeiroJogador, numeroJogador);
						printf("Deseja substituir por qual jogador?");
						printf("Numero da camisa: ");
						scanf("%d", &numeroJogador);
						adicionarJogadores(primeiroJogador, numeroJogador);
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
							
							if(primeiroJogador == NULL) {
								printf("[ERROR] Escalacao inexistente :(\n");
							} else {
								printf("\n");
								separador();
								printf("\tTime Titular\n");
								separador();
								mostrarEscalacaoOrdem(primeiroJogador);
								printf("\n");
							}
							
							break;
							
						case 2:
							
							if(primeiroJogador == NULL) {
								printf("[ERROR] Escalacao inexistente :(\n");
							} else{
								printf("\n");
								separador();
								printf("\tTime Titular\n");
								separador();
								mostrarEscalacaoPosOrdem(primeiroJogador);
								printf("\n");
							}
							
							break;
							
						case 3:
							
							condicao = 1;
							
							break;
							
						default:
							printf("[ERROR] Opcao invalida x(\n");
					}
					
				} while(condicao != 1);
				
				break;
				
			case 3:
				
				printf("Camisa do jogador: ");
				scanf("%d", &numeroJogador);
				substituirJogador(primeiroJogador, numeroJogador);
				
				break;
				
			case 4:
				condicao = 2;
				break;
				
			default:
				printf("[ERROR] Opcao invalida x(\n");
		}
		
	} while(condicao != 2);
	
	printf("Obrigado por usar nossos servicos :)\n");
	
	return 0;
}

Time *criarTime(int numeroJogador) {
	Time *jogadores = malloc(sizeof(Time));
	
	printf("Nome: ");
	scanf("%s", jogadores->nomeJogador);
	jogadores->numeroJogador = numeroJogador;
	jogadores->direita = NULL;
	jogadores->esquerda = NULL;
	
	return jogadores;
}

void adicionarJogadores(Time *jogadores, int numeroJogador) {
	
	if(numeroJogador > jogadores->numeroJogador) {
		
		if(jogadores->direita == NULL) {
			jogadores->direita = criarTime(numeroJogador);
		} else {
			adicionarJogadores(jogadores->direita, numeroJogador);
		}
		
	} else {
		
		if(jogadores->esquerda == NULL) {
			jogadores->esquerda = criarTime(numeroJogador);
		} else{
			adicionarJogadores(jogadores->esquerda, numeroJogador);
		}
		
	}
	
}

void mostrarEscalacaoOrdem(Time *jogadores) {
	
	if(jogadores == NULL) {
		return;
	}
	
	mostrarEscalacaoOrdem(jogadores->esquerda);
	printf("%s - %d\n", jogadores->nomeJogador, jogadores->numeroJogador);
	mostrarEscalacaoOrdem(jogadores->direita);
}

void mostrarEscalacaoPosOrdem(Time *jogadores) {
	
	if(jogadores == NULL) {
		return;
	}
	
	mostrarEscalacaoPosOrdem(jogadores->esquerda);
	mostrarEscalacaoPosOrdem(jogadores->direita);
	printf("%s - %d\n", jogadores->nomeJogador, jogadores->numeroJogador);
}

void separador() {
	printf("---------------------------------\n");
}

void substituirJogador(Time *jogadores, int numeroJogador) {
	Time *escalacaoAnterior = jogadores;
	Time *novaEscalacao;
	
	do{
		novaEscalacao = escalacaoAnterior;
		
		if(numeroJogador > escalacaoAnterior->numeroJogador) {
			escalacaoAnterior = escalacaoAnterior->direita;
		} else if(numeroJogador < escalacaoAnterior->numeroJogador) {
			escalacaoAnterior = escalacaoAnterior->esquerda;
		}
		
	} while(escalacaoAnterior != NULL && escalacaoAnterior->numeroJogador != numeroJogador);
	
	if(escalacaoAnterior != NULL) {
		
		printf("\nJogador de camisa %d sera substituido\n", numeroJogador);
		
		if(escalacaoAnterior->esquerda == NULL && escalacaoAnterior->direita == NULL) {
			
			if(novaEscalacao->esquerda == escalacaoAnterior) {
				novaEscalacao->esquerda = NULL;
			}
			if(novaEscalacao->direita == escalacaoAnterior) {
				novaEscalacao->direita = NULL;
			}
			
		}
		
		if(escalacaoAnterior->esquerda != NULL && escalacaoAnterior->direita == NULL) {
			
			if(novaEscalacao->esquerda == escalacaoAnterior) {
				novaEscalacao->esquerda = escalacaoAnterior->esquerda;
			}
			if(novaEscalacao->direita == escalacaoAnterior) {
				novaEscalacao->direita = escalacaoAnterior->esquerda;
			}
			
		}
		
		if(escalacaoAnterior->esquerda == NULL && escalacaoAnterior->direita != NULL) {
			
			if(novaEscalacao->esquerda == escalacaoAnterior) {
				novaEscalacao->esquerda = novaEscalacao->direita;
			}
			if(novaEscalacao->direita == escalacaoAnterior) {
				novaEscalacao->direita = novaEscalacao->direita;
			}
			
		}
		
		if(escalacaoAnterior->esquerda != NULL && escalacaoAnterior->direita != NULL) {
			
			if(escalacaoAnterior->esquerda->direita == NULL) {
				escalacaoAnterior->numeroJogador = escalacaoAnterior->esquerda->numeroJogador;
				escalacaoAnterior->esquerda = NULL;
			} else {
				Time *jogadoresReservas = escalacaoAnterior->esquerda;
				Time *jogadoresTitulares = jogadoresReservas;
				
				while(jogadoresReservas->direita != NULL) {
					jogadoresTitulares = jogadoresReservas;
					jogadoresReservas = jogadoresReservas->direita;
				}
				
				jogadoresTitulares->direita = NULL;
				escalacaoAnterior->numeroJogador = jogadoresReservas->numeroJogador;
			}
			
		}
		
	} else {
		printf("[ERROR] Jogador de camisa %d nao esta na partida\n", numeroJogador);
	}
}
