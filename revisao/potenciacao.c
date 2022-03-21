#include <stdio.h>

	/*	ALUNO: Antonio Claudio Teixeira Alves
	Escreva uma função potencia(base, expoente) que, quando chamada,
	retorne base elevado ao expoente. Por exemplo, potencia(3, 4) deve retornar 81. Assuma que expoente
	é um inteiro maior ou igual a 1.*/
	
void separador();

int potencia(int base, int expoente);

int main(){
	int base, expoente, potenciacao;
	char condicao;
	
	separador();
	printf("\tPOTENCIACAO\n");
	separador();
	
	do {
		printf("Base: ");
		scanf("%d", &base);
		printf("Expoente: ");
		scanf("%d", &expoente);
		
		if(expoente < 0) {
			separador();
			printf("[ERRO] Expoente Negativo x(\n");
			separador();
		} else {
			potenciacao = potencia(base, expoente);	
			
			separador();
			printf("Potencia: %d\n", potenciacao);
			separador();
		}
		
		printf("Deseja continuar [s / n]: ");
		scanf("%s", &condicao);
		separador();
	} while(condicao != 'n');
	
	separador();
	printf("Obrigado por usar nosso servico :)\n");
	
	return 0;
}

void separador() {
	printf("--------------------------------\n");
}

int potencia(int base, int expoente) {
	
	if(expoente == 0) {
		return 1;
	}
	
	return base * potencia(base, expoente - 1);
}
