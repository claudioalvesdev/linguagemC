#include <stdio.h>
#include <stdlib.h>

	/*	ALUNO: Antonio Claudio Teixeira Alves
	Escreva um programa que cadastre uma lista de números. Deve-se ter uma função para remover
	da lista os números negativos.*/
	
struct numeros{
	int valor;
	struct numeros *prox;
};

typedef struct numeros Lista;
Lista *primeiroNumero, *numerosPositivos;

void separador() {
	printf("--------------------\n");
}

void adicionarNumeros();

void mostrarNumeros(Lista *valores);

void adicionarSomenteNumerosPositivos(int numeros);

Lista *verificarPositivos(Lista *valores);

int main() {
	int auxiliar = 0, opcao;
	char condicao;
	Lista *listaDeNumerosPositivos;
	
	do{
		separador();
		printf("\tMENU\n");
		separador();
		printf("[1] - Inserir valores\n");
		printf("[2] - Mostrar Lista Completa\n");
		printf("[3] - Mostrar Somente\nNumeros Negativos\n");;
		printf("[4] - Sair\n");
		separador();
		printf("Sua opcao: ");
		scanf("%d", &opcao);
		
		switch(opcao) {
			case 1:
				
				do {
					adicionarNumeros();
					printf("Desejar continuar? [s / n]: ");
					scanf("%s", &condicao);
				} while(condicao != 'n');
				
				break;
				
			case 2:
				
				mostrarNumeros(primeiroNumero);
				printf("\n");
				
				break;
				
			case 3:
				
				listaDeNumerosPositivos = verificarPositivos(primeiroNumero);
				mostrarNumeros(numerosPositivos);
				printf("\n");
				
				break;
				
			case 4:
				
				printf("Obrigado por usar nossos servicos ;)\n");
				auxiliar = 1;
				
				break;
				
			default:
				printf("[ERROR] Opcao invalida x(\n");
		}
		
	} while(auxiliar != 1);
	
	return 0;
}

void adicionarNumeros() {
	Lista *valores = malloc(sizeof(Lista));
	
	printf("Digite o valor: ");
	scanf("%d", &valores->valor);
	valores->prox = NULL;
	
	if(primeiroNumero == NULL) {
		primeiroNumero = valores;
	} else{
		Lista *auxiliarLista = primeiroNumero;
		
		while(auxiliarLista->prox != NULL) {
			auxiliarLista = auxiliarLista->prox;
		}
		
		auxiliarLista->prox = valores;
	}
	
}

void mostrarNumeros(Lista *valores) {
	
	if(valores != NULL) {
		printf("%2d ", valores->valor);
		mostrarNumeros(valores->prox);
	}
	
}

void adicionarSomenteNumerosPositivos(int numeros) {
	Lista *valoresPositivos = malloc(sizeof(Lista));
	
	valoresPositivos->valor = numeros;
	valoresPositivos->prox = NULL;
	
	if(valoresPositivos == NULL) {
		numerosPositivos = valoresPositivos;
	} else{
		Lista *auxiliarPositivos = numerosPositivos;
		
		while(auxiliarPositivos->prox != NULL) {
			auxiliarPositivos = auxiliarPositivos->prox;
		}
		
		auxiliarPositivos->prox = valoresPositivos;
	}
}

Lista *verificarPositivos(Lista *valores) {
	
	if(valores != NULL) {
		
		if(valores->valor >= 0) {
			adicionarSomenteNumerosPositivos(valores->valor);
			verificarPositivos(valores->prox);
		} else{
			verificarPositivos(valores->prox);
		}
		
	}
	
	return numerosPositivos;
}
