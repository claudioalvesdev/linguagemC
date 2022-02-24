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
	struct arvore *noDireita;
	struct arvore *noEsquerda;
};

typedef struct arvore Nodo;

Nodo *criarNo(int valor);

void adicionarNo(Nodo *no, int valor);

void mostrarArvore(Nodo *no);

void separador();

int quantidadeDeNo(Nodo *no) ;

int maiorAlturaDaArvore(int valorEsquerda, int valorDireita) ;

int alturaDoMaiorNo(Nodo *no) ;

int maiorValorDaArvore(Nodo *no);

void removerNo(Nodo *no, int valor);

int main() {
	int opcao, contador = 0, valor, escolha = 0, qtdNo, alturaArvore, maiorValor;
	char condicao;
	Nodo *noRaiz;
	
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
						noRaiz = criarNo(valor);
					} else {
						printf("Digite o valor: ");
						scanf("%d", &valor);
						adicionarNo(noRaiz, valor);
					}
					
					contador++;
					
					printf("Desejar continuar? [s / n] : ");
					scanf("%s", &condicao);
					
				} while(condicao != 'n');
				
				break;
				
			case 2:
				
				printf("\nOs valores adicionados sao: \n");
				mostrarArvore(noRaiz);
				printf("\n");
				
				break;
			
			case 3:
				
				qtdNo = quantidadeDeNo(noRaiz);
				printf("Quantidade de nos: %d\n", qtdNo);
				
				break;
			
			case 4: 
				
				alturaArvore = alturaDoMaiorNo(noRaiz);
				printf("Altura da arvore: %d\n", alturaArvore);
				
				break;
				
			case 5:
				
				maiorValor = maiorValorDaArvore(noRaiz);
				printf("O maior valor : %d\n", maiorValor);
				
				break;
				
			case 6:
				
				printf("Deseja remover qual numero?\n");
				printf("Valor: ");
				scanf("%d", &valor);
				removerNo(noRaiz, valor);
				
				break;
				
			case 7:
				
				escolha = 2;
				
				break;
				
			default:
				printf("[ERROR] Opcao invalida x(\n");
		}
		
	} while(escolha != 2);
	
	printf("Obrigado por usar nossos servicos :)\n");

	
	return 0;
}

Nodo *criarNo(int valor) {
	Nodo *no = malloc(sizeof(Nodo));
	
	no->valor = valor;
	no->noDireita = NULL;
	no->noEsquerda = NULL;
	
	return no;
}

void adicionarNo(Nodo *no, int valor) {
	
	if(valor > no->valor) {
		
		if(no->noDireita == NULL) {
			no->noDireita = criarNo(valor);
		} else {
			adicionarNo(no->noDireita, valor);
		}
		
	} else {
		
		if(no->noEsquerda == NULL) {
			no->noEsquerda = criarNo(valor);
		} else {
			adicionarNo(no->noEsquerda, valor);
		}
		
	}
	
}

void mostrarArvore(Nodo *no) {
	
	if(no == NULL) {
		return;
	}
	
	mostrarArvore(no->noEsquerda);
	printf("%d ", no->valor);
	mostrarArvore(no->noDireita);
}

void separador() {
	printf("------------------------------\n");
}

int quantidadeDeNo(Nodo *no) {
	
	if(no == NULL) {
		return 0;
	} else {
		return 1 + quantidadeDeNo(no->noDireita) + quantidadeDeNo(no->noEsquerda);
	}
	
}

int maiorAlturaDaArvore(int valorEsquerda, int valorDireita) {
	
	if(valorEsquerda > valorDireita) {
		return valorEsquerda;
	} else {
		return valorDireita;
	}
}

int alturaDoMaiorNo(Nodo *no) {
	
	if((no == NULL) || (no->noDireita == NULL && no->noEsquerda == NULL)) {
		return 0;
	} else {
		return 1 + maiorAlturaDaArvore(alturaDoMaiorNo(no->noEsquerda), alturaDoMaiorNo(no->noDireita));
	}
}

int maiorValorDaArvore(Nodo *no) {
	
	if(no->noDireita != NULL) {
		return maiorValorDaArvore(no->noDireita);
	} else {
		return no->valor;
	}
	
}

void removerNo(Nodo *no, int valor) {
	Nodo *noAtual = no;
	Nodo *noAnterior;
	
	do{
		noAnterior = noAtual;
		
		if(valor < noAtual->valor) {
			noAtual = noAtual->noEsquerda;
		} else if(valor > noAtual->valor) {
			noAtual = noAtual->noDireita;
		}
		
	} while(noAtual != NULL && valor != noAtual->valor);
	
	if(noAtual != NULL) {
		
		if(noAtual->noDireita == NULL  && noAtual->noEsquerda == NULL) {
			
			if(noAnterior->noDireita == noAtual) {
				noAnterior->noDireita = NULL; 
			}
			
			if(noAnterior->noEsquerda == noAtual) {
				noAnterior->noEsquerda = NULL;
			}
			
		}
		
		if (noAtual->noDireita != NULL && noAtual->noEsquerda == NULL) {
			
			if(noAnterior->noDireita == noAtual) {
				noAnterior->noDireita = noAtual->noDireita;
			}
			
			if(noAnterior->noEsquerda == noAtual) {
				noAnterior->noEsquerda = noAtual->noDireita;
			}
			
		}
		
		if(noAtual->noEsquerda != NULL && noAtual->noDireita == NULL) {
			
			if(noAnterior->noDireita == noAtual) {
				noAnterior->noDireita = noAtual->noEsquerda;
			}
			
			if(noAnterior->noEsquerda == noAtual) {
				noAnterior->noEsquerda = noAtual->noEsquerda;
			}
			
		}
		
		if(noAtual->noDireita != NULL && noAtual->noEsquerda != NULL) {
			
			if(noAtual->noEsquerda->noDireita == NULL) {
				noAtual->valor = noAtual->noEsquerda->valor;
			} else {
				Nodo *novoNo = noAtual->noEsquerda;
				Nodo *noAuxiliar = novoNo;
				
				while(novoNo->noDireita != NULL) {
					noAuxiliar = novoNo;
					novoNo = novoNo->noDireita;
				}
				
				noAuxiliar->noDireita = NULL;
				noAtual->valor = novoNo->valor;
			}
			
		}
		
	} else {
		printf("[ERRO] Nao foi possivel fazer essa alteracao :(\n");
	}
}

