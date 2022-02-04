#include <stdio.h>
#include <stdlib.h>
#define MAX 10

	/*	ALUNO: Antonio Claudio Teixeira Alves
	Projete uma estrutura do tipo pilha (stack/LIFO) sequencial de
	10 espaços para guardar informações de páginas da web visitadas.
	Essas informações estarão contidas na seguinte struct:
	
	#define MAX 10
	Struct historico{
 		char adress[30];
	 	Struct historico *prox;
	}

	1 – Armazenar O site visitado
	2 – Remover o site  (opção de voltar)
	3 – Exibir o site atual (Topo)*/

struct historico{
	char address[30];
	struct historico *prox;
};

typedef struct historico Web;
Web *topo;
int tamanho = 0;

void separador();

void adicionar_pag();

void remover_pag_atual();

void mostrar_pag_atual();

void mostrar_historico(Web *sites);

void liberar(Web *sites);

int main() {
	int aux = 0, escolha;
	char condicao;
	
	do{
		separador();
		printf("\tPAGINAS WEB\n");
		separador();
		printf("[1] - Adicionar site\n");
		printf("[2] - Remover pag. atual\n");
		printf("[3] - Mostrar pag. atual\n");
		printf("[4] - Mostrar historico\n");
		printf("[5] - Sair\n");
		separador();
		printf("Sua opcao: ");
		scanf("%d", &escolha);
		
		switch(escolha) {
			case 1:
				condicao = 's';
				
				while(condicao != 'n') {
					adicionar_pag();
					
					printf("Desejar continuar [s / n]: ");
					scanf("%s", &condicao);
				}
				
				break;
			case 2:
				
				remover_pag_atual();
				break;
			case 3:
				
				mostrar_pag_atual();
				break;
			case 4:
				
				if(topo == NULL) {
					printf("[ERROR] Paginas inexistentes x(\n");
				} else{
					mostrar_historico(topo);	
				}
				break;
			case 5:
				
				aux = 1;
				break;
			default:
				
				printf("[ERROR] Opcao invalida x(\n");
		}
			
	} while(aux != 1);
	
	liberar(topo);
	
	
	return 0;
}

void separador() {
	printf("---------------------------\n");
}

void adicionar_pag() {
	Web *sites = malloc(sizeof(Web));
	char opcao;
	
	if(tamanho == MAX) {
		
		separador();
		printf("[ERROR] Voce atingiu o numero\n");
		printf("maximo de paginas cadastradas\n");
		separador();
		printf("Desejar excluir a pagina anterior? [s / n]: ");
		scanf("%s", &opcao);
		separador();
		
		if(opcao == 's') {
			
			remover_pag_atual();
			adicionar_pag();	
		} else{
			
			printf("Esse e seu historico atual ;)\n\n");
			mostrar_historico(topo);
			separador();
		}
		
	} else{
		
		fflush(stdin);
		printf("Site: ");
		gets(sites->address);
	
		sites->prox = topo;
		topo = sites;
		tamanho++;	
	}
}

void remover_pag_atual() {
	if(topo == NULL) {
		printf("[ERROR] Historico inexistente :x\n");
	} else{
		Web *remover = topo;
		
		topo = topo->prox;
		free(remover);
		printf("Remocao feita com sucesso : ) !!!\n");
		tamanho--;
	}
}

void mostrar_pag_atual() {
	if(topo == NULL) {
		printf("[ERROR] Nenhuma pagina aberta :x\n");
	} else{
		Web *atual = topo;
		
		printf("Pagina atual: %s\n", atual->address);
	}
}

void mostrar_historico(Web *sites) {
	if(sites != NULL) {
		printf("Site: %s\n", sites->address);
		mostrar_historico(sites->prox);
	}
}

void liberar(Web *sites) {
	if(sites != NULL) {
		liberar(sites->prox);
		
		free(sites);
	}
}
