#include <stdio.h>
#include <stdlib.h>
#include <string.h>

	/* ALUNO: Antonio Claudio Teixeira Alves
	Fazer um programa para simular uma agenda de telefones utilizando Listas Encadeadas. Para cada pessoa devem-se
	ter os seguintes dados: (STRUCT)
		• Nome
		• E-mail
		• Endereço (contendo campos para Rua, número, complemento, bairro, cep, cidade,
		estado, pais).
		• Telefone (contendo campo para DDD e número)
		• Data de aniversário (contendo campo para dia, mês, ano).
		• Observações: Uma linha (string) para alguma observação especial.

	a) O programa deve usar Lista encadeada para Cadastrar Pessoa no topo da lista
	b) mostrar os dados da agenda.
	c) Buscar por nome da pessoa e mostrar os dados da agenda - Caso a pessoa nao exista, mostrar uma mensagem informando.
	d) O programa deve ter um menu principal oferecendo as opções acima.*/
	
struct dadosPessoais {
	char nome[80];
	char email[80];
	char observacao[20];
};

struct endereco {
	char rua[40];
	char cidade[40];
	char complemento[40];
	char bairro[30];
	char estado[30];
	char pais[30];
	char cep[12];
	char numeroDaCasa[8];
};

struct telefone {
	int ddd;
	int numeroDeTelefone;
};

struct aniversario {
	int dia;
	int mes;
	int ano;
};

struct cadastro {
	struct dadosPessoais pessoais;
	struct endereco Endereco;
	struct telefone Telefone;
	struct aniversario Aniversario;
	struct cadastro *prox;
};

typedef struct cadastro Cadastro;
Cadastro *primeiroCliente;

void separador();

void adicionarClientes();

void mostrarClientes(Cadastro *clientes);

void procurarNome(Cadastro *clientes, char pesquisarNome[]);

int main() {
	int opcao, auxiliar;
  	char condicao, nome[80];
	
	do{
		separador();
		printf("\tMENU\n");
		separador();
		printf("[1] - Abrir agenda\n");
		printf("[2] - Sair\n");
		separador();
		printf("Sua opcao: ");
		scanf("%d", &opcao);
		
		switch(opcao) {
			
			case 1:
				
				do {
					separador();
					printf("[1] - Inserir contato no topo\n");
					printf("[2] - Ver todos os contatos\n");
					printf("[3] - Procurar contatos por nome\n");
					printf("[4] - Voltar\n");
					separador();
					printf("Sua opcao: ");
					scanf("%d", &opcao);
					
					switch(opcao) {
						
						case 1:
							
							do{
								adicionarClientes();
								fflush(stdin);
								printf("Deseja continuar [s / n] : ");
								scanf("%s", &condicao);
							} while(condicao != 'n');
							
							break;
							
						case 2: 
						
							mostrarClientes(primeiroCliente);
							
							break;
							
						case 3:
							
							fflush(stdin);
							printf("Informe o nome desejado: ");
							scanf("%s", &nome);
							procurarNome(primeiroCliente, nome);
							
							break;
							
						case 4:
							
							auxiliar = 2;
							
							break;
							
						default:
							printf("\n[ERRO] Opcao Invalida :(\n");
							
					}	
					
				} while(auxiliar != 2);
				
				break;
				
			case 2:
				
				auxiliar = 1;
				
				break;
				
			default:
				printf("\n[ERRO] Opcao Invalida :(\n");
				
		}
		
	} while(auxiliar != 1);
	
	printf("Obrigado por usar nossos servicos :)\n");
	
	return 0;
}

void separador() {
	printf("---------------------------\n");
}

void adicionarClientes() {
	Cadastro *clientes = malloc(sizeof(Cadastro));
	
	fflush(stdin);
	printf("Nome: ");
    gets(clientes->pessoais.nome);
    
	fflush(stdin);	
	printf("E-mail: ");
	gets(clientes->pessoais.email);
							
	fflush(stdin);
	printf("Endereco \n");
	printf("Rua: ");
	gets(clientes->Endereco.rua);
							
	fflush(stdin);
	printf("Numero: ");
	gets(clientes->Endereco.numeroDaCasa);
							
	fflush(stdin);
	printf("Complemento: ");
	gets(clientes->Endereco.complemento);
							
	fflush(stdin);
	printf("Bairro: ");
	gets(clientes->Endereco.bairro);
							
	fflush(stdin);
	printf("CEP: ");
	gets(clientes->Endereco.cep);
						
	fflush(stdin);
	printf("Cidade: ");
	gets(clientes->Endereco.cidade);
					
	fflush(stdin);
	printf("Estado: ");
	gets(clientes->Endereco.estado);
						
	fflush(stdin);
	printf("Pais: ");
	gets(clientes->Endereco.pais);
					
	fflush(stdin);
	printf("Telefone\n");
	printf("DDD: ");
	scanf("%d", &clientes->Telefone.ddd);
						
	fflush(stdin);
	printf("N Telefone: ");
	scanf("%d", &clientes->Telefone.numeroDeTelefone);
					
	fflush(stdin);
	printf("Aniversario\n");
	printf("Dia: ");
	scanf("%d", &clientes->Aniversario.dia);
							
	fflush(stdin);
	printf("Mes: ");
	scanf("%d", &clientes->Aniversario.mes);
								
	fflush(stdin);
	printf("Ano: ");
	scanf("%d", &clientes->Aniversario.ano);
							
	fflush(stdin);
	printf("Obersavacao: ");
	gets(clientes->pessoais.observacao);
	
	clientes->prox = primeiroCliente;
    primeiroCliente = clientes;
}

void mostrarClientes(Cadastro *clientes) {
	
	if(clientes != NULL) {
		printf("\nNome: %s\n", clientes->pessoais.nome);
		printf("E-mail: %s\n", clientes->pessoais.email);
		printf("Endereco: Rua %s %s %s ", clientes->Endereco.rua, clientes->Endereco.numeroDaCasa, clientes->Endereco.bairro);
		printf("%s\n%s %s %s %s\n", clientes->Endereco.cep, clientes->Endereco.cidade, clientes->Endereco.estado, 
		clientes->Endereco.pais, clientes->Endereco.complemento);
		printf("Telefone: (%d) %d\n", clientes->Telefone.ddd, clientes->Telefone.numeroDeTelefone);
		printf("Data de nascimento: %d/%d/%d\n", clientes->Aniversario.dia, clientes->Aniversario.mes, clientes->Aniversario.ano);
		printf("Observacao: %s\n\n\n", clientes->pessoais.observacao);
		mostrarClientes(clientes->prox);
	}
	
}

void procurarNome(Cadastro *clientes, char pesquisarNome[]) {
	
	if(clientes != NULL) {
		
		if(strcmp(pesquisarNome, clientes->pessoais.nome) == 0) {
			printf("\nNome: %s\n", clientes->pessoais.nome);
			printf("E-mail: %s\n", clientes->pessoais.email);
			printf("Endereco: Rua %s %s %s ", clientes->Endereco.rua, clientes->Endereco.numeroDaCasa, clientes->Endereco.bairro);
			printf("%s\n%s %s %s %s\n", clientes->Endereco.cep, clientes->Endereco.cidade, clientes->Endereco.estado, 
			clientes->Endereco.pais, clientes->Endereco.complemento);
			printf("Telefone: (%d) %d\n", clientes->Telefone.ddd, clientes->Telefone.numeroDeTelefone);
			printf("Data de nascimento: %d/%d/%d\n", clientes->Aniversario.dia, clientes->Aniversario.mes, clientes->Aniversario.ano);
			printf("Observacao: %s\n\n\n", clientes->pessoais.observacao);
		}	
		
		procurarNome(clientes->prox, pesquisarNome);
	}
	
}





