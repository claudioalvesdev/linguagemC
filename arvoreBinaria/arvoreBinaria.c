#include <stdio.h>
#include <stdlib.h>
	
	/*	ALUNO: Antonio Claudio Teixeira Alves
	Deve criar uma árvore binária, com a inseração de valores e depois um método para mostrar a árvore
	*/

struct arvore {
	int valor;
	struct arvore *direita;
	struct arvore *esquerda;
};

typedef struct arvore Arvore;

Arvore *criar(int valor);

void adicionar(Arvore *sub_arvores, int valor);

void mostrar_arvore(Arvore *sub_arvores);

void remocao(Arvore *sub_arvores, int valor);

int main() {
	Arvore *raiz = criar(21);
	
	adicionar(raiz, 17);
	adicionar(raiz, 11);
	adicionar(raiz, 7);
	adicionar(raiz, 13);
	adicionar(raiz, 19);
	adicionar(raiz, 31);
	adicionar(raiz, 41);
	adicionar(raiz, 23);

	mostrar_arvore(raiz);
	printf("\n");
	remocao(raiz, 17);
	mostrar_arvore(raiz);
	
	return 0;
}

Arvore *criar(int valor) {
	Arvore *sub_arvores = malloc(sizeof(Arvore));
	
	sub_arvores->valor = valor;
	sub_arvores->direita = NULL;
	sub_arvores->esquerda = NULL;
	
	return sub_arvores;
}

void adicionar(Arvore *sub_arvores, int valor) {
	
	if(valor < sub_arvores->valor) {
		
		if(sub_arvores->esquerda == NULL) {
			sub_arvores->esquerda = criar(valor);
		} else {
			adicionar(sub_arvores->esquerda, valor);
		}
		
	} else {
		
		if(sub_arvores->direita == NULL) {
			sub_arvores->direita = criar(valor);
		} else {
			adicionar(sub_arvores->direita, valor);
		}
		
	}
	
}

void mostrar_arvore(Arvore *sub_arvores) {
	
	if(sub_arvores == NULL) {
		return;
	}
	
	mostrar_arvore(sub_arvores->esquerda);
	printf("%d ", sub_arvores->valor);
	mostrar_arvore(sub_arvores->direita);
}

void remocao(Arvore *sub_arvores, int valor) {
	Arvore *filho = sub_arvores;
	Arvore *pai;
	
	do{
		pai = filho;
		
		if(valor < filho->valor) {
			filho = filho->esquerda;
		} else if(valor > filho->valor) {
			filho = filho->direita;
		}
		
	} while(filho != NULL && valor != filho->valor);
	
	if(filho != NULL) {
		
		if(filho->direita == NULL  && filho->esquerda == NULL) {
			
			if(pai->direita == filho) {
				pai->direita = NULL; 
			}
			
			if(pai->esquerda == filho) {
				pai->esquerda = NULL;
			}
			
		}
		
		if (filho->direita != NULL && filho->esquerda == NULL) {
			
			if(pai->direita == filho) {
				pai->direita = filho->direita;
			}
			
			if(pai->esquerda == filho) {
				pai->esquerda = filho->direita;
			}
			
		}
		
		if(filho->esquerda != NULL && filho->direita == NULL) {
			
			if(pai->direita == filho) {
				pai->direita = filho->esquerda;
			}
			
			if(pai->esquerda == filho) {
				pai->esquerda = filho->esquerda;
			}
			
		}
		
		if(filho->direita != NULL && filho->esquerda != NULL) {
			
			if(filho->esquerda->direita == NULL) {
				filho->valor = filho->esquerda->valor;
			} else {
				Arvore *p = filho->esquerda;
				Arvore *aux = p;
				
				while(p->direita != NULL) {
					aux = p;
					p = p->direita;
				}
				
				aux->direita = NULL;
				filho->valor = p->valor;
			}
			
		}
		
	}
}

