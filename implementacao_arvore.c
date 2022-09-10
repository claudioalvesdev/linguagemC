#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *esq;
    struct no *dir;
} Arv;

Arv *inserir_no(Arv *raiz, int numero) {
    if (raiz == NULL) {
        Arv *aux = (Arv*)malloc(sizeof(Arv));
        aux->valor = numero;
        aux->esq = NULL;
        aux->dir = NULL;
      return aux;
    } else {
      if (numero > raiz->valor) {
        raiz->dir = inserir_no(raiz->dir, numero);
      } else {
        raiz->esq = inserir_no(raiz->esq, numero);
      }
      return raiz;
    }
}

void mostrar_arvore(Arv *raiz) {
  if (raiz != NULL) {
    mostrar_arvore(raiz->esq);
    printf("%d\n", raiz->valor);
    mostrar_arvore(raiz->dir);
  }
}


int quantidade_no(Arv *raiz) {
  if(raiz != NULL) {
    return 1 + quantidade_no(raiz->esq) + quantidade_no(raiz->dir);
  } else {
    return 0;
  }
}

int no_nao_folha(Arv *raiz) {
    if(raiz != NULL) {
        if (raiz->esq != NULL || raiz->dir != NULL) {
            return 1 + no_nao_folha(raiz->esq) + no_nao_folha(raiz->dir);
        }
    }
}

int quantidade_folhas(Arv *raiz) {
    if(raiz == NULL) {
        return 0;
    }
    if(raiz->esq == NULL && raiz->dir ==  NULL) {
        return 1;
    }
    
    return quantidade_folhas(raiz->esq) + quantidade_folhas(raiz->dir);
    
}

int altura_arvore(Arv *raiz) {
	if (raiz != NULL) {
		int lado_esquerdo = altura_arvore(raiz->esq);
		int lado_direito = altura_arvore(raiz->dir);
		
		if (lado_esquerdo > lado_direito) {
		    return 1 + lado_esquerdo;  
		} else {
		    return 1 + lado_direito;    
		}
	}
	return 0;
}


void buscar_impar(Arv *raiz, int numero) {
    if(raiz != NULL) {
        if(raiz->valor % 2 != 0) {
            if(raiz->valor == numero) {
                printf("O valor %d foi encontrada\n", numero);
            }
        }
        buscar_impar(raiz->dir, numero);
        buscar_impar(raiz->esq, numero);
    } 
}

int maior_valor = 0;
void maior_numero(Arv *raiz) {
    if(raiz != NULL) {
        if(raiz->valor > maior_valor) {
            maior_valor = raiz->valor;
        }
        
        maior_numero(raiz->esq);
        maior_numero(raiz->dir);
    }
}

int valor_maximo(Arv *raiz) {
    Arv *aux = raiz;
    if(raiz != NULL) {
        while(aux->dir != NULL) {
            aux = aux->dir;
        }
        return aux->valor;
    }
}

int menor_valor(Arv *raiz) {
    Arv *aux = raiz;
    if(raiz != NULL) {
        while(aux->esq != NULL) {
            aux = aux->esq;
        }
        return aux->valor;
    }
}

int main() {
    Arv *raiz = NULL;
    int qtd_no, qtd_no_nao_folha, qtd_folha, altura;
    raiz = inserir_no(raiz, 20);
    raiz = inserir_no(raiz, 15);
    raiz = inserir_no(raiz, 11);
    raiz = inserir_no(raiz, 10);
    raiz = inserir_no(raiz, 12);
    raiz = inserir_no(raiz, 18);
    raiz = inserir_no(raiz, 22);
    raiz = inserir_no(raiz, 21);
    raiz = inserir_no(raiz, 30);
    raiz = inserir_no(raiz, 25);
    raiz = inserir_no(raiz, 40);
    raiz = inserir_no(raiz, 23);
    qtd_no = quantidade_no(raiz);
    qtd_no_nao_folha = no_nao_folha(raiz);
    qtd_folha = quantidade_folhas(raiz);
    altura = altura_arvore(raiz);
    mostrar_arvore(raiz);
    printf("%d %d %d %d", qtd_no, qtd_no_nao_folha, qtd_folha, altura);
    return 0;
}
