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
Web *primeiroSite;
int qtdDeSites = 0;

void separador();

void adicionarPaginas();

void removerPaginaAtual();

void mostrarPaginaAtual();

void mostrarHistorico(Web *sites);

void liberar(Web *sites);

int main() {
	int auxiliar = 0, opcao;
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
		scanf("%d", &opcao);
		
		switch(opcao) {
			
			case 1:
				
				do{
					adicionarPaginas();
					printf("Desejar continuar [s / n]: ");
					scanf("%s", &condicao);	
				} while(condicao != 'n');
				
				break;
				
			case 2:
				
				removerPaginaAtual();
				
				break;
				
			case 3:
				
				mostrarPaginaAtual();
				
				break;
				
			case 4:
				
				if(primeiroSite == NULL) {
					printf("[ERROR] Paginas inexistentes x(\n");
				} else{
					mostrarHistorico(primeiroSite);	
				}
				
				break;
				
			case 5:
				
				auxiliar = 1;
				
				break;
				
			default:
				printf("[ERROR] Opcao invalida x(\n");
		}
			
	} while(auxiliar != 1);
	
	liberar(primeiroSite);
	
	printf("Obrigado por usar nossos servicos :)\n");
	
	return 0;
}

void separador() {
	printf("---------------------------\n");
}

void adicionarPaginas() {
	Web *sites = malloc(sizeof(Web));
	char condicao;
	
	if(qtdDeSites == MAX) {
		
		separador();
		printf("[ERROR] Voce atingiu o numero\n");
		printf("maximo de paginas cadastradas\n");
		separador();
		printf("Desejar excluir a pagina anterior? [s / n]: ");
		scanf("%s", &condicao);
		separador();
		
		if(condicao == 's') {
			removerPaginaAtual();
			adicionarPaginas();	
		} else{
			printf("Esse e seu historico atual ;)\n\n");
			mostrarHistorico(primeiroSite);
			separador();
		}
		
	} else{
		
		fflush(stdin);
		printf("Site: ");
		gets(sites->address);
	
		sites->prox = primeiroSite;
		primeiroSite = sites;
		qtdDeSites++;	
	}
}

void removerPaginaAtual() {
	
	if(primeiroSite == NULL) {
		printf("[ERROR] Historico inexistente :x\n");
	} else{
		Web *removerSite = primeiroSite;
		
		primeiroSite = primeiroSite->prox;
		free(removerSite);
		printf("Remocao feita com sucesso : ) !!!\n");
		qtdDeSites--;
	}
	
}

void mostrarPaginaAtual() {
	
	if(primeiroSite == NULL) {
		printf("[ERROR] Nenhuma pagina aberta :x\n");
	} else{
		Web *siteAtual = primeiroSite;
		
		printf("Pagina atual: %s\n", siteAtual->address);
	}
	
}

void mostrarHistorico(Web *sites) {
	
	if(sites != NULL) {
		printf("Site: %s\n", sites->address);
		mostrarHistorico(sites->prox);
	}
	
}

void liberar(Web *sites) {
	
	if(sites != NULL) {
		liberar(sites->prox);
		
		free(sites);
	}
	
}
