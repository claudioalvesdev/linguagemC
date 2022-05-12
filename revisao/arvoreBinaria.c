#include <stdio.h>
#include <stdlib.h>

struct no {
	int valor;
	struct no *direita;
	struct no *esquerda;
};

typedef struct no No;

No *inicializarArvore();

No *inserirElemento(No *elemento, int valor) ;

void mostrarElemento(No *elemento);

No *removerNo(No *elemento, int valor) {
    if(elemento == NULL) {
        return NULL;
    } else if(elemento->valor > valor) {
        elemento->esquerda = removerNo(elemento->esquerda, valor);
    } else if(elemento->valor < valor) {
        elemento->direita = removerNo(elemento->direita, valor);
    } else {
        
    // NÓ FOLHA
    if(elemento->esquerda == NULL && elemento->direita == NULL) {
        free(elemento);
        
        return NULL;
    } else if(elemento->esquerda == NULL) {
        No *aux = elemento;
        elemento = elemento->direita;
        free(t);
        
        return elemento;
    } else if(elemento->direita == NULL) {
        No *aux = elemento;
        elemento = elemento->esquerda;
        free(aux);
        
        return elemento;
    }
}

int main() {
	No *elemento = inicializarArvore();
	elemento = inserirElemento(elemento, 10);
	elemento = inserirElemento(elemento, 5);
	elemento = inserirElemento(elemento, 2);
	
	mostrarElemento(elemento);
	return 0;
}

No *inicializarArvore() {
	return NULL;
}

No *inserirElemento(No *elemento, int valor) {
	if(elemento == NULL) {
		elemento = (No*)malloc(sizeof(No));
		
		elemento->valor = valor;
		elemento->direita = NULL;
		elemento->esquerda = NULL;
		
	} else if(valor > elemento->valor) {
		elemento->direita = inserirElemento(elemento->direita, valor);
	} else if(valor < elemento->valor) {
		elemento->esquerda = inserirElemento(elemento->esquerda, valor);	
	}
	
	return elemento;
	
}

void mostrarElemento(No *elemento) {
	if(elemento != NULL) {
		mostrarElemento(elemento->esquerda);
		mostrarElemento(elemento->direita);
		printf("%d ", elemento->valor);
	}
}
