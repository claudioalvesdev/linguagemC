#include <stdio.h>
	
	/*	ALUNO: Antonio Claudio Teixeira Alves
	Faca um programa que armazene em um registro de dados (estrutura composta)
	os dados de um funcionario de uma empresa, compostos de: Nome, Idade, Sexo (M/F),
	CPF, Data de Nascimento, Codigo do Setor onde trabalha (0-99), Cargo que ocupa (string
	de ate 30 caracteres) e Salario. Os dados devem ser digitados pelo usuario, 
	armazenados na estrutura e exibidos na tela.*/
	
struct nascimento{
	int dia, mes, ano;
};	

struct empresa{
	char nome[80];
	int idade;
	char sexo[1];
	char cpf[14];
	struct nascimento Nascimento;
	char codigoSetor[100];
	char cargo[30];
	float salario;
};

typedef struct empresa Empresa;

int main() {
	Empresa funcionario[2];
	
	for(int i = 0; i < 2; i++) {
		printf("Cadastro de Funcionarix %d\n", i + 1);
		fflush(stdin);
		printf("Nome: ");
		gets(funcionario[i].nome);
		
		printf("Idade: ");
		scanf("%d", &funcionario[i].idade);
		
		fflush(stdin);
		printf("Sexo [F / M]: ");
		gets(funcionario[i].sexo);
		
		fflush(stdin);
		printf("CPF: ");
		gets(funcionario[i].cpf);
		
		printf("Data de Nascimento\n");
		printf("Dia: ");
		scanf("%d", &funcionario[i].Nascimento.dia);
		printf("Mes: ");
		scanf("%d", &funcionario[i].Nascimento.mes);
		printf("Ano: ");
		scanf("%d", &funcionario[i].Nascimento.ano);
		
		fflush(stdin);
		printf("Codigo do Setor: ");
		gets(funcionario[i].codigoSetor);
		
		fflush(stdin);
		printf("Cargo na empresa: ");
		gets(funcionario[i].cargo);
		
		printf("Salario (em reais): ");
		scanf("%f", &funcionario[i].salario);	
		
		printf("\n\n");	
	}
	
	for(int i = 0; i < 2; i++) {
		printf("Nome: %s\n", funcionario[i].nome);
		printf("CPF: %s\n", funcionario[i].cpf);
		printf("Data de Nascimento: %d/ 0%d/ %d\n", funcionario[i].Nascimento.dia, funcionario[i].Nascimento.mes, funcionario[i].Nascimento.ano);
		printf("Idade: %d\n", funcionario[i].idade);
		printf("Sexo: %s\n", funcionario[i].sexo);
		printf("Cargo na empresa: %s\n", funcionario[i].cargo);
		printf("Codigo do Setor: %s\n", funcionario[i].codigoSetor);
		printf("Salario: %.2f\n", funcionario[i].salario);
		printf("\n\n");
	}
	
	
	return 0;
}
