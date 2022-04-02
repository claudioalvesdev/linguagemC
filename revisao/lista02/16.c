#include <stdio.h>

	/*	ALUNO: Antonio Claudio Teixeira Alves
	Faca um programa que seja uma agenda de compromissos e:
		• Crie e leia um vetor de 5 estruturas de dados com: compromisso
		(maximo 60 letras) e data. A data deve ser outra estrutura de dados
		contendo dia, mes e ano.
		• Leia dois inteiros M e A e mostre todos os compromissos do mes M 
		do ano A. Repita o procedimento ate ler M = 0.*/
		
struct data{
	int dia, mes, ano;
};

struct dados{
	char compromisso[60];
	struct data Data;
};

typedef struct dados Agenda;

void separador();

int main() {
	Agenda pessoas[5];
	int m = 1, a;
	
	separador();
	printf("AGENDA DE COMPROMISSOS\n");
	separador();
	
	for(int i = 0; i < 5; i++) {
		printf("Data\n");
		printf("Dia: ");
		scanf("%d", &pessoas[i].Data.dia);
		printf("Mes: ");
		scanf("%d", &pessoas[i].Data.mes);
		printf("Ano: ");
		scanf("%d", &pessoas[i].Data.ano);
		
		fflush(stdin);
		printf("Compromisso: ");
		gets(pessoas[i].compromisso);
		printf("\n");
	}
	
	do{
		printf("Deseja ver os compromisso de qual data?\n");
		printf("Mes: ");
		scanf("%d", &m);
		printf("Ano: ");
		scanf("%d", &a);
		printf("\n");
		
		for(int i = 0; i < 5; i++) {
			if(pessoas[i].Data.mes == m && pessoas[i].Data.ano == a) {
				printf("Data\n");
				printf("%d / %d / %d\n", pessoas[i].Data.dia, pessoas[i].Data.mes, pessoas[i].Data.ano);
				printf("Compromisso:\n%s\n\n", pessoas[i].compromisso);
			}
		}
	} while(m != 0);
	
	return 0;
}

void separador() {
	printf("----------------------------\n");
}
