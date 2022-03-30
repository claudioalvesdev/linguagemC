#include <stdio.h>

	/*	ALUNO: Antonio Claudio Teixeira Alves
	Escreva um trecho de codigo para fazer a criacao dos novos tipos de dados
	conforme solicitado abaixo:
		• Horario: composto de hora, minutos e segundos.
		• Data: composto de dia, mes e ano.
		• Compromisso: composto de uma data, horario e texto que descreve o compromisso.*/

struct horario {
	int hora, min, seg;
};

struct data {
	int data, mes, ano;
};

struct compromisso{
	struct data Data;
	struct horario Horario;
	char texto[100];
};

int main() {
	
	return 0;
}
