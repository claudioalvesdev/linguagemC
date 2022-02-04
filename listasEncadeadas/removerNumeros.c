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
Lista *primeiro, *positivos;

void separador() {
	printf("--------------------\n");
}

void add_numero() {
	Lista *valores = malloc(sizeof(Lista));
	
	printf("Digite o valor: ");
	scanf("%d", &valores->valor);
	
	valores->prox = NULL;
	if(primeiro == NULL) {
		primeiro = valores;
	} else{
		Lista *aux_v = primeiro;
		
		while(aux_v->prox != NULL) {
			aux_v = aux_v->prox;
		}
		
		aux_v->prox = valores;
	}
	
}

void mostrar_n(Lista *valores) {
	if(valores != NULL) {
		printf("%2d ", valores->valor);
		mostrar_n(valores->prox);
	}
}

void add_positivos(int numeros) {
	Lista *valores_p = malloc(sizeof(Lista));
	
	valores_p->valor = numeros;

	valores_p->prox = NULL;
	if(positivos == NULL) {
		positivos = valores_p;
	} else{
		Lista *aux_p = positivos;
		
		while(aux_p->prox != NULL) {
			aux_p = aux_p->prox;
		}
		
		aux_p->prox = valores_p;
	}
}

Lista *verificar_positivos(Lista *valores) {
	
	if(valores != NULL) {
		if(valores->valor >= 0) {
			add_positivos(valores->valor);
			verificar_positivos(valores->prox);
		} else{
			verificar_positivos(valores->prox);
		}
		
	}
	
	return positivos;
}

int main() {
	int auxiliar = 0, escolha;
	char condicao = 's';
	Lista *nova_lista;
	
	do{
		separador();
		printf("\tMENU\n");
		separador();
		printf("[1] - Inserir valores\n");
		printf("[2] - Listar valores\n");
		printf("[3] - Listar Naturais\n");;
		printf("[4] - Sair\n");
		separador();
		printf("Sua opcao: ");
		scanf("%d", &escolha);
		
		switch(escolha) {
			case 1:
				condicao = 's';
				while(condicao != 'n') {
					add_numero();
					printf("Desejar continuar? [s / n]: ");
					scanf("%s", &condicao);
				}
				break;
			case 2:
				mostrar_n(primeiro);
				printf("\n");
				break;
			case 3:
				nova_lista = verificar_positivos(primeiro);
				mostrar_n(positivos);
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
