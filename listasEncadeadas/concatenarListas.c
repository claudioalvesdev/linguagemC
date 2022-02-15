#include <stdio.h>
#include <stdlib.h>

	/*	ALUNO: Antonio Claudio Teixeira Alves
	Escreva uma função que receba, como parâmetros, duas lista L1 e L2 e concatene L1 no final de
	L2. Utilize o protótipo: Lista *concatena(Lista *L1, Lista *L2)*/

struct pontos{
	int valor;
	struct pontos *prox;
};

typedef struct pontos Lista;
Lista *primeiroNumeroLista1, *primeiroNumeroLista2;

void separador();

Lista *adicionarLista1();

Lista *adicionarLista2();

void mostrarListas(Lista *lista);

Lista *concatenar(Lista *lista1, Lista *lista2);

int main() {
	int auxiliar = 0, opcao;
	char condicao;
	Lista *lista1, *lista2, *listaConcatenada;
	
	do{
		separador();
		printf("\tMenu\n");
		separador();
		printf("[1] - Lista A\n");
		printf("[2] - Lista B\n");
		printf("[3] - Mostrar Listas Juntas\n");
		printf("[4] - Sair\n");
		separador();
		printf("Sua opcao: ");
		scanf("%d", &opcao);
			
		switch(opcao) {
			case 1:
				
				do{
					separador();
					printf("\tLista A\n");
					printf("[1] - Inserir Valores\n");
					printf("[2] - Mostrar Valores\n");
					printf("[3] - Voltar\n");
					separador();
					printf("Sua opcao: ");
					scanf("%d", &opcao);
					
					switch(opcao) {
						case 1:
							
							do{
								lista1 = adicionarLista1();
								printf("Deseja continuar? [s / n] : ");
								scanf("%s", &condicao);
							} while(condicao != 'n');
							
							break;
							
						case 2:
							
							mostrarListas(primeiroNumeroLista1);
							printf("\n");
							
							break;
							
						case 3:
							
							auxiliar = 2;
							
							break;
							
						default:
							printf("[ERROR] Opcao Invalida x(\n");
					}
					
				} while(auxiliar != 2);
				
				break;
				
			case 2:
				do{
					separador();
					printf("\tLista B\n");
					printf("[1] - Inserir Valores\n");
					printf("[2] - Mostrar Valores\n");
					printf("[3] - Voltar\n");
					separador();
					printf("Sua opcao: ");
					scanf("%d", &opcao);
					
					switch(opcao) {
						case 1:
							
							do {
								lista2 = adicionarLista2();
								printf("Deseja continuar? [s / n] : ");
								scanf("%s", &condicao);
							} while(condicao != 'n');
							
							break;
							
						case 2:
							
							mostrarListas(primeiroNumeroLista2);
							printf("\n");
							
							break;
							
						case 3:
							
							auxiliar = 3;
							
							break;
							
						default:
							printf("[ERROR] Opcao Invalida x(\n");
					}
					
				} while(auxiliar != 3);
				
				break;
				
			case 3:
				
				if(primeiroNumeroLista2 == NULL) {
					printf("[ERROR] Lista B esta vazia !!!\n");
				} else{
					listaConcatenada = concatenar(lista1, lista2);
					mostrarListas(primeiroNumeroLista2);
					printf("\n");	
				}
				
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
	printf("-----------------------------\n");
}

Lista *adicionarLista1() {
	Lista *lista1 = malloc(sizeof(Lista));
	
	printf("Digite o valor: ");
	scanf("%d", &lista1->valor);
	
	lista1->prox = primeiroNumeroLista1;
	primeiroNumeroLista1 = lista1;
	
	return lista1;
}

Lista *adicionarLista2() {
	Lista *lista2 = malloc(sizeof(Lista));
	
	printf("Digite o valor: ");
	scanf("%d", &lista2->valor);
	
	lista2->prox = primeiroNumeroLista2;
	primeiroNumeroLista2 = lista2;
	
	return lista2;
}

void mostrarListas(Lista *lista) {
	
	if(lista != NULL) {
		printf("%2d ", lista->valor);
		mostrarListas(lista->prox);
	}
	
}

Lista *concatenar(Lista *lista2, Lista *lista1) {
	Lista *listaConcatenada = lista2;
	
	while(listaConcatenada->prox != NULL) {
		listaConcatenada = listaConcatenada->prox;
	}
	
	listaConcatenada->prox = lista1;	
	
	return listaConcatenada;
}


