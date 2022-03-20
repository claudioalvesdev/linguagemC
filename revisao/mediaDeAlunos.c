#include <stdio.h>

	/*	ALUNO: Antonio Claudio Teixeira Alves
	Escrever um programa em "C" que solicita as notas das duas provas
	feitas por cada um dos alunos de uma turma (as notas tem de estar no
	intervalo [0 10]) e imprime para cada um a média das notas. O programa
	deve parar imediatamente após ter sido digitado o valor 50 para a nota
	da primeira prova.*/
	
void separador();

int main() {
	float primeiraNota, segundaNota;
	char condicao;
	
	separador();
	printf("\tMEDIA DE NOTAS\n");
	separador();
	
	printf("OBS:. O programa para quando digitado 50 na nota 01\n");
	separador();
	
	do{
		printf("Nota 01: ");
		scanf("%f", &primeiraNota);
		
		if(primeiraNota == 50) {
			break;
		}
		
		printf("Nota 02: ");
		scanf("%f", &
		segundaNota);
		
		separador();
		if((primeiraNota >= 0 && primeiraNota < 11) && (segundaNota >= 0 && segundaNota <= 10)) {
			printf("Nota 01: %.2f\n", primeiraNota);
			printf("Nota 02: %.2f\n", segundaNota);
			printf("Media: %.2f\n", (primeiraNota + segundaNota)/2);
		} else {
			printf("[ERRO] Alguma nota esta incorreta x(\n");
		}
		separador();
		
		printf("Deseja continuar [s/ n]: ");
		scanf("%s", &condicao);
		separador();
	} while(condicao != 'n');
	
	printf("Obrigado por usar nosso servico :)\n");
	
	return 0;
}

void separador() {
	printf("-------------------------------\n");
}
