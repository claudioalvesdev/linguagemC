#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *esq;
    struct no *dir;
    int fb;
} Arv;

int altura_arvore(Arv *raiz) {
	if(raiz == NULL) {
	    return -1;
	} else {
	    return raiz->fb;
	}
}

int maior(int valor_esq, int valor_dir) {
	
	if(valor_esq > valor_dir) {
		return valor_esq;
	} else {
		return valor_dir;
	}
}

int fator_balenceamento(Arv *raiz) {
    if (raiz == NULL) {
        return (altura_arvore(raiz->esq) - altura_arvore(raiz->dir));
    } else {
        return 0;
    }
}

Arv *rotacao_esq(Arv *raiz) {
    Arv *aux, *temp;
    
    aux = raiz->dir;
    temp = aux->esq;
    
    aux->esq = raiz;
    temp->dir = temp;
    
    raiz->fb = maior(altura_arvore(raiz->esq), altura_arvore(raiz->dir) + 1);
    aux->fb = maior(altura_arvore(temp->esq), altura_arvore(temp->dir) + 1);
    
    return aux;
}

Arv *rotacao_dir(Arv *raiz) {
    Arv *aux, *temp;
    
    aux = raiz->esq;
    temp = aux->dir;
    
    aux->dir = raiz;
    raiz->esq = temp;
    
    raiz->fb = maior(altura_arvore(raiz->esq), altura_arvore(raiz->dir) + 1);
    aux->fb = maior(altura_arvore(aux->esq), altura_arvore(aux->dir) + 1);
    
    return aux;
}

Arv *rotacao_dupla_esq(Arv *raiz) {
    raiz->dir = rotacao_dir(raiz->dir);
    return rotacao_esq(raiz);
}

Arv *rotacao_dupla_dir(Arv *raiz) {
    raiz->esq = rotacao_esq(raiz->esq);
    return rotacao_dir(raiz);
}

Arv *balancear(Arv *raiz) {
    int fb = fator_balenceamento(raiz);
    
    if(fb < -1 && fator_balenceamento(raiz->dir) <= 0) {
        raiz = rotacao_esq(raiz);
    } else if(fb > 1 && fator_balenceamento(raiz->esq) >= 0) {
        raiz = rotacao_dir(raiz);
    } else if(fb > 1 && fator_balenceamento(raiz->esq) < 0) {
        raiz = rotacao_dupla_dir(raiz);
    } else if(fb < -1 && fator_balenceamento(raiz->dir) > 0) {
        raiz = rotacao_dupla_esq(raiz);
    }
    
    return raiz;
}

Arv *criar_no(Arv *raiz, int numero) {
    if (raiz == NULL) {
        Arv *aux = (Arv*)malloc(sizeof(Arv));
        aux->valor = numero;
        aux->fb = 0;
        aux->esq = NULL;
        aux->dir = NULL;
      return aux;
    } else {
      if (numero > raiz->valor) {
        raiz->dir = criar_no(raiz->dir, numero);
      } else if(numero < raiz->valor) {
        raiz->esq = criar_no(raiz->esq, numero);
      } 
      
      raiz->fb = maior(altura_arvore(raiz->esq), altura_arvore(raiz->dir) + 1);
      
      raiz = balancear(raiz);
      
      return raiz;
    }
}

void removerNo(Arv *raiz, int valor) {
	Arv *no_atual = raiz;
	Arv *no_anterior;
	
	do{
		no_anterior = no_atual;
		
		if(valor < no_atual->valor) {
			no_atual = no_atual->esq;
		} else if(valor > no_atual->valor) {
			no_atual = no_atual->dir;
		}
		
	} while(no_atual != NULL && valor != no_atual->valor);
	
	if(no_atual != NULL) {
		
		if(no_atual->dir == NULL  && no_atual->esq == NULL) {
			
			if(no_anterior->dir == no_atual) {
				no_anterior->dir = NULL; 
			}
			
			if(no_anterior->esq == no_atual) {
				no_anterior->esq = NULL;
			}
			
		}
		
		if (no_atual->dir != NULL && no_atual->esq == NULL) {
			
			if(no_anterior->dir == no_atual) {
				no_anterior->dir = no_atual->dir;
			}
			
			if(no_anterior->esq == no_atual) {
				no_anterior->esq = no_atual->dir;
			}
			
		}
		
		if(no_atual->esq != NULL && no_atual->dir == NULL) {
			
			if(no_anterior->dir == no_atual) {
				no_anterior->dir = no_atual->esq;
			}
			
			if(no_anterior->esq == no_atual) {
				no_anterior->esq = no_atual->esq;
			}
			
		}
		
		if(no_atual->dir != NULL && no_atual->esq != NULL) {
			
			if(no_atual->esq->dir == NULL) {
				no_atual->valor = no_atual->esq->valor;
			} else {
				Arv *novo_no = no_atual->esq;
				Arv *no_auxiliar = novo_no;
				
				while(novo_no->dir != NULL) {
					no_auxiliar = novo_no;
					novo_no = novo_no->dir;
				}
				
				no_auxiliar->dir = NULL;
				no_atual->valor = novo_no->valor;
			}
			
		}
		
	} else {
		printf("[ERRO] Nao foi possivel fazer essa alteracao :(\n");
	}
}
