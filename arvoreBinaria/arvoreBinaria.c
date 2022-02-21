#include <stdio.h>
#include <stdlib.h>
	
	/*	ALUNO: Antonio Claudio Teixeira Alves
	Deve criar uma árvore binária, com a inseração de valores e depois um método para mostrar a árvore
	*/

struct arvore {
	int valor;
	struct arvore *noDireita;
	struct arvore *noEsquerda;
};

typedef struct arvore Arvore;

Arvore *criarNo(int valor);

void adicionarNo(Arvore *no, int valor);

void mostrarArvore(Arvore *no);

void excluirNo(Arvore *no, int valor);

int main() {
	Arvore *raiz = criarNo(21);
	
	adicionarNo(raiz, 17);
	adicionarNo(raiz, 11);
	adicionarNo(raiz, 7);
	adicionarNo(raiz, 13);
	adicionarNo(raiz, 19);
	adicionarNo(raiz, 31);
	adicionarNo(raiz, 41);
	adicionarNo(raiz, 23);

	mostrarArvore(raiz);
	printf("\n");
	excluirNo(raiz, 17);
	mostrarArvore(raiz);
	
	return 0;
}

Arvore *criarNo(int valor) {
	Arvore *no = malloc(sizeof(Arvore));
	
	no->valor = valor;
	no->noDireita = NULL;
	no->noEsquerda = NULL;
	
	return no;
}

void adicionarNo(Arvore *no, int valor) {
	
	if(valor < no->valor) {
		
		if(no->noEsquerda == NULL) {
			no->noEsquerda = criarNo(valor);
		} else {
			adicionarNo(no->noEsquerda, valor);
		}
		
	} else {
		
		if(no->noDireita == NULL) {
			no->noDireita = criarNo(valor);
		} else {
			adicionarNo(no->noDireita, valor);
		}
		
	}
	
}

void mostrarArvore(Arvore *no) {
	
	if(no == NULL) {
		return;
	}
	
	mostrarArvore(no->noEsquerda);
	printf("%d ", no->valor);
	mostrarArvore(no->noDireita);
}

void excluirNo(Arvore *no, int valor) {
	Arvore *noAtual = no;
	Arvore *noAnterior;
	
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
				Arvore *novoNo = noAtual->noEsquerda;
				Arvore *noAuxiliar = novoNo;
				
				while(novoNo->noDireita != NULL) {
					noAuxiliar = novoNo;
					novoNo = novoNo->noDireita;
				}
				
				noAuxiliar->noDireita = NULL;
				noAtual->valor = novoNo->valor;
			}
			
		}
		
	}
}

