#include <stdio.h>
#include <stdlib.h>

	/*	ALUNO: Antonio Claudio Teixeira Alves
	Desenvolva uma árvore simples e além das funções básicas(criar, listar, remover), 
	implemente  as seguintes funções: (2,5 pontos) 
	a) Função para contar o número de nós na árvore 
	b) Função para calcular a altura  
	c) Função para achar o maior número
	*/
	
struct arvore {
	int valor;
	struct arvore *direita;
	struct arvore *esquerda;
};

typedef struct arvore Nodo;

Nodo *criar_nodo(int valor);

void adicionar_nodo(Nodo *no, int valor);

void mostrar_arvore(Nodo *no);

void separador();

int quantidade_nodo(Nodo *no) ;

int maior_altura(int valor_esquerda, int valor_direita) ;

int altura_nodo(Nodo *no) ;

int maior_valor_da_arvore(Nodo *no);

void remover_nodo(Nodo *no, int valor);

int main() {
	int opcao, contador = 0, valor, condicao = 0, no_quantidade, altura_arvore, maior_valor;
	char escolha;
	Nodo *no_raiz;
	
	do {
		separador();
		printf("\tArvore Binaria\n");
		separador();
		printf("[1] - Inserir Valores\n");
		printf("[2] - Mostrar Valores\n");
		printf("[3] - Exibir quantidade de no\n");
		printf("[4] - Mostrar altura da arvore\n");
		printf("[5] - Exibir maior valor\n");
		printf("[6] - Remover nodo\n");
		printf("[7] - Sair\n");
		separador();
		printf("Sua escolha: ");
		scanf("%d", &opcao);
		
		switch(opcao) {
			case 1: 
				
				do{
					if(contador == 0) {
						printf("Digite o valor: ");
						scanf("%d", &valor);
						no_raiz = criar_nodo(valor);
					} else {
						printf("Digite o valor: ");
						scanf("%d", &valor);
						adicionar_nodo(no_raiz, valor);
					}
					
					contador++;
					
					printf("Desejar continuar? [s / n] : ");
					scanf("%s", &escolha);
					
				} while(escolha != 'n');
				
				break;
				
			case 2:
				
				printf("\nOs valores adicionados sao: \n");
				mostrar_arvore(no_raiz);
				printf("\n");
				
				break;
			
			case 3:
				
				no_quantidade = quantidade_nodo(no_raiz);
				printf("Quantidade de nos: %d\n", no_quantidade);
				
				break;
			
			case 4: 
				
				altura_arvore = altura_nodo(no_raiz);
				printf("Altura da arvore: %d\n", altura_arvore);
				
				break;
				
			case 5:
				
				maior_valor = maior_valor_da_arvore(no_raiz);
				printf("O maior valor : %d\n", maior_valor);
				
				break;
				
			case 6:
				
				printf("Deseja remover qual numero?\n");
				printf("Valor: ");
				scanf("%d", &valor);
				remover_nodo(no_raiz, valor);
				
				break;
				
			case 7:
				
				condicao = 2;
				
				break;
				
			default:
				printf("[ERROR] Opcao invalida x(\n");
		}
		
	} while(condicao != 2);

	
	return 0;
}

Nodo *criar_nodo(int valor) {
	Nodo *no = malloc(sizeof(Nodo));
	
	no->valor = valor;
	no->direita = NULL;
	no->esquerda = NULL;
	
	return no;
}

void adicionar_nodo(Nodo *no, int valor) {
	
	if(valor > no->valor) {
		
		if(no->direita == NULL) {
			no->direita = criar_nodo(valor);
		} else {
			adicionar_nodo(no->direita, valor);
		}
		
	} else {
		
		if(no->esquerda == NULL) {
			no->esquerda = criar_nodo(valor);
		} else {
			adicionar_nodo(no->esquerda, valor);
		}
		
	}
	
}

void mostrar_arvore(Nodo *no) {
	
	if(no == NULL) {
		return;
	}
	
	mostrar_arvore(no->esquerda);
	printf("%d ", no->valor);
	mostrar_arvore(no->direita);
}

void separador() {
	printf("------------------------------\n");
}

int quantidade_nodo(Nodo *no) {
	
	if(no == NULL) {
		return 0;
	} else {
		return 1 + quantidade_nodo(no->direita) + quantidade_nodo(no->esquerda);
	}
	
}

int maior_altura(int valor_esquerda, int valor_direita) {
	
	if(valor_esquerda > valor_direita) {
		return valor_esquerda;
	} else {
		return valor_direita;
	}
}

int altura_nodo(Nodo *no) {
	
	if((no == NULL) || (no->direita == NULL && no->esquerda == NULL)) {
		return 0;
	} else {
		return 1 + maior_altura(altura_nodo(no->esquerda), altura_nodo(no->direita));
	}
}

int maior_valor_da_arvore(Nodo *no) {
	
	if(no->direita != NULL) {
		return maior_valor_da_arvore(no->direita);
	} else {
		return no->valor;
	}
	
}

void remover_nodo(Nodo *no, int valor) {
	Nodo *filho = no;
	Nodo *pai;
	
	do{
		pai = filho;
		
		if(valor < filho->valor) {
			filho = filho->esquerda;
		} else if(valor > filho->valor) {
			filho = filho->direita;
		}
		
	} while(filho != NULL && filho->valor != valor);
	
	if(filho != NULL) {
		
		printf("\nValor %d removido com sucesso\n", valor);
				
		if(filho->esquerda == NULL && filho->direita == NULL) {
			
			if(pai->esquerda == filho) {
				pai->esquerda = NULL;
			}
			if(pai->direita == filho) {
				pai->direita = NULL;
			}
			
		}
		
		if(filho->esquerda != NULL && filho->direita == NULL) {
			
			if(pai->esquerda == filho) {
				pai->esquerda = filho->esquerda;
			}
			if(pai->direita == filho) {
				pai->direita = filho->esquerda;
			}
			
		}
		
		if(filho->esquerda == NULL && filho->direita != NULL) {
			
			if(pai->esquerda == filho) {
				pai->esquerda = filho->direita;
			}
			if(pai->direita == filho) {
				pai->direita = filho->direita;
			}
			
		}
		
		if(filho->esquerda != NULL && filho->direita != NULL) {
			
			if(filho->esquerda->direita == NULL) {
				filho->valor = filho->esquerda->valor;
				filho->esquerda = NULL;
			} else {
				Nodo *no_aux = filho->esquerda;
				Nodo *aux = no_aux;
				
				while(no_aux->direita != NULL) {
					aux = no_aux;
					no_aux = no_aux->direita;
				}
				
				aux->direita = NULL;
				filho->valor = no_aux->valor;
			}
			
		}
	} else {
		printf("\n[ERROR] Valor nao encontrado X(\n");
	}
}

