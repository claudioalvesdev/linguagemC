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

int main() {
    Arv *raiz = NULL;
    int qtd_no, qtd_no_nao_folha;
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
    no = no_nao_folha(raiz);
    mostrar_arvore(raiz);
    printf("%d %d", qtd_no, qtd_no_nao_folha);
    return 0;
}
