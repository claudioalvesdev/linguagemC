#include <stdio.h>
#include <stdlib.h>

	/*	ALUNO: Antonio Claudio Teixeira Alves
	Considere a implementação de listas encadeadas utilizando ponteiros. Escreva uma função void
	Inverte(TipoLista *Lista) que, dada uma lista com um número qualquer de elementos, inverte a
	ordem dos elementos da lista, como exemplificado na figura abaixo*/
	
struct ponto{
	int numero;
	struct ponto *prox;
};

typedef struct ponto Valores;
Valores *primeiro;

void separador();

void add_numeros();

void imprimir(Valores *lista);

void inverte(Valores *lista);

void liberar(Valores *lista);

int main() {
	int auxiliar = 0, escolha;
	char condicao = 's';
	
	do{
		separador();
		printf("\tMenu\n");
		separador();
		printf("[1] - Inserir numero\n");
		printf("[2] - Listar numeros\n");
		printf("[3] - Numeros ordem inversa\n");
		printf("[4] - Sair\n");
		separador();
		printf("Sua opcao: ");
		scanf("%d", &escolha);
			
		switch(escolha) {
			case 1:
				condicao = 's';
				
				while(condicao != 'n') {
					add_numeros();
					printf("Deseja continuar? [s / n] : ");
					scanf("%s", &condicao);
				}
				break;
			case 2:
				
				imprimir(primeiro);
				printf("\n");
				break;
			case 3:
				
				inverte(primeiro);
				printf("\n");
				break;
			case 4:
				
				printf("Obrigado por usar nossos servicos ;)\n");
				auxiliar = 1;
				break;
			default:
				
				printf("[ERROR] Opcao Invalida x(\n");
		}
	} while(auxiliar != 1);
	
	return 0;
}

void separador() {
	printf("----------------------------\n");
}

void add_numeros() {
	Valores *lista = malloc(sizeof(Valores));
	
	printf("Digite o valor: ");
	scanf("%d", &lista->numero);
	
	lista->prox = primeiro;
	primeiro = lista;
}

void imprimir(Valores *lista) {
	if(lista != NULL) {
		printf("%d ", lista->numero);
		imprimir(lista->prox);
	}
}


void inverte(Valores *lista) {
	Valores *anterior, *atual, *seguinte;
	
	atual = lista;
	seguinte = lista->prox;
	
	while(atual != NULL) {
		seguinte = atual->prox;
		atual->prox = anterior;
		anterior = atual;
		atual = seguinte;
	}
	
	
	while(anterior != NULL) {
		printf("%d ", anterior->numero);
		anterior = anterior->prox;
	}
}

void liberar(Valores *lista) {
	if(lista != NULL) {
		liberar(lista->prox);
		free(lista);
	}
}
