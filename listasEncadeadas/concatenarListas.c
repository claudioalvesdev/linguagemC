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
Lista *primeiro_L1, *primeiro_L2;

void separador();

Lista *add_L1();

Lista *add_L2();

void mostrar_L(Lista *L);

Lista *concatena(Lista *L1, Lista *L2);

void liberar_L1(Lista *L1);

void liberar_L2(Lista *L1);

int main() {
	int auxiliar = 0, escolha;
	char condicao = 's';
	Lista *L1, *L2, *L3;
	
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
		scanf("%d", &escolha);
			
		switch(escolha) {
			case 1:
				do{
					separador();
					printf("\tLista A\n");
					printf("[1] - Inserir Valores\n");
					printf("[2] - Mostrar Valores\n");
					printf("[3] - Voltar\n");
					separador();
					printf("Sua opcao: ");
					scanf("%d", &escolha);
					
					switch(escolha) {
						case 1:
							condicao = 's';
							while(condicao != 'n') {
								L1 = add_L1();
								printf("Deseja continuar? [s / n] : ");
								scanf("%s", &condicao);
							}
							break;
							
						case 2:
							mostrar_L(primeiro_L1);
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
					scanf("%d", &escolha);
					
					switch(escolha) {
						case 1:
							condicao = 's';
							while(condicao != 'n') {
								L2 = add_L2();
								printf("Deseja continuar? [s / n] : ");
								scanf("%s", &condicao);
							}
							break;
							
						case 2:
							mostrar_L(primeiro_L2);
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
				
				if(primeiro_L2 == NULL) {
					printf("[ERROR] Lista B esta vazia !!!\n");
				} else{
					L3 = concatena(L1, L2);
					mostrar_L(primeiro_L2);
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

Lista *add_L1() {
	Lista *L1 = malloc(sizeof(Lista));
	
	printf("Digite o valor: ");
	scanf("%d", &L1->valor);
	
	L1->prox = primeiro_L1;
	primeiro_L1 = L1;
	
	return L1;
}

Lista *add_L2() {
	Lista *L2 = malloc(sizeof(Lista));
	
	printf("Digite o valor: ");
	scanf("%d", &L2->valor);
	
	L2->prox = primeiro_L2;
	primeiro_L2 = L2;
	
	return L2;
}

void mostrar_L(Lista *L) {
	if(L != NULL) {
		printf("%2d ", L->valor);
		mostrar_L(L->prox);
	}
}

Lista *concatena(Lista *L1, Lista *L2) {
	Lista *copia = L2;
	
	while(copia->prox != NULL) {
		copia = copia->prox;
	}
	
	copia->prox = L1;
	
	return copia;
}


