#include <stdio.h>
#include <stdlib.h>

	/*	ALUNO: Antonio Claudio Teixeira Alves
	Considere a implementação de listas encadeadas utilizando ponteiros. Escreva uma função void
	Inverte(TipoLista *Lista) que, dada uma lista com um número qualquer de elementos, inverte a
	ordem dos elementos da lista, como exemplificado na figura abaixo */
	
struct ponto{
	int numero;
	struct ponto *prox;
};

typedef struct ponto Valores;
Valores *primeiroNumero;

void separador();

void adicionarNumeros();

void mostrarNumeros(Valores *lista);

void inverterNumeros(Valores *lista);

void liberarNumeros(Valores *lista);

int main() {
	int auxiliar = 0, opcao;
	char condicao;
	
	do{
		
		separador();
		printf("\tMenu\n");
		separador();
		printf("[1] - Inserir numeros\n");
		printf("[2] - Mostrar numeros\n");
		printf("[3] - Inverter numeros\n");
		printf("[4] - Sair\n");
		separador();
		printf("Sua opcao: ");
		scanf("%d", &opcao);
			
		switch(opcao) {
			
			case 1:
			
				do{
					
					adicionarNumeros();
					printf("Deseja continuar? [s / n] : ");
					scanf("%s", &condicao);
					
				} while(condicao != 'n');
	
				break;
				
			case 2:
				
				if(primeiroNumero == NULL) {
					printf("Lista de numeros esta vazia ainda :/\n");
				} else {
					mostrarNumeros(primeiroNumero);	
					printf("\n");
				}
				
				break;
							
			case 3:
				
				inverterNumeros(primeiroNumero);
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

void adicionarNumeros() {
	Valores *lista = malloc(sizeof(Valores));
	
	printf("Digite o valor: ");
	scanf("%d", &lista->numero);
	
	lista->prox = primeiroNumero;
	primeiroNumero = lista;
}

void mostrarNumeros(Valores *lista) {
	
	if(lista != NULL) {
		printf("%d ", lista->numero);
		mostrarNumeros(lista->prox);
	}
	
}


void inverterNumeros(Valores *lista) {
	Valores *numeroAnterior, *numeroAtual = lista, *numeroSeguinte = lista->prox;
	
	while(numeroAtual != NULL) {
		numeroSeguinte = numeroAtual->prox;
		numeroAtual->prox = numeroAnterior;
		numeroAnterior = numeroAtual;
		numeroAtual = numeroSeguinte;
	}
	
	primeiroNumero = numeroAnterior;
}

void liberarNumeros(Valores *lista) {
	
	if(lista != NULL) {
		liberarNumeros(lista->prox);
		free(lista);
	}
	
}
