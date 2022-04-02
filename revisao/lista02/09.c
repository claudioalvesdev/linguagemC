#include <stdio.h>

	/*	ALUNO: Antonio Claudio Teixeira Alves
	Faca um programa que faca operacoes simples de numeros complexos:  
	
		• Crie e leia dois numeros complexos z e w, compostos por parte real
		e parte imaginaria.
		• Apresente a soma, subtracao e produto entre z e w, nessa ordem, bem
		como o modulo de ambos.*/

struct numeros{
	float z, w;
};

typedef struct numeros Complexo;

void separador();

void mostrarValores(Complexo valores[2]);

void moduloValores(Complexo valores[2]);

int main() {
	Complexo valores[2];
	
	separador();
	printf("OPERACOES COM NUMEROS COMPLEXOS\n");
	separador();
	
	for(int i = 0; i < 2; i++) {
		printf("Valores do Z%d\n", i + 1);
		printf("Parte Real: ");
		scanf("%f", &valores[i].z);
		printf("Parte Imaginaria: ");
		scanf("%f", &valores[i].w);
		printf("\n\n");
	}
	
	printf("SOMA\n");
	mostrarValores(valores);
	printf("Z3 = %.2f %.2fi\n\n", (valores[0].z + valores[1].z), (valores[0].w + valores[1].w));
	
	printf("SUBTRACAO\n");
	mostrarValores(valores);
	printf("Z3 = %.2f %.2fi\n\n", (valores[0].z - valores[1].z), (valores[0].w - valores[1].w));
	
	printf("MULTIPLICACAO\n");
	mostrarValores(valores);
	printf("Z3 = %.2f %.2fi\n\n", (valores[0].z*valores[1].z - valores[0].w*valores[1].w), (valores[0].z*valores[1].w + valores[0].w*valores[1].z));
	
	printf("MODULO\n");
	moduloValores(valores);	
	
	return 0;
}

void separador() {
	printf("---------------------------------\n");
}

void mostrarValores(Complexo valores[2]) {
	for(int i = 0; i < 2; i++) {
		printf("Z%d = %.2f %.2fi\n", i + 1, valores[i].z, valores[i].w);	
	}
}

void moduloValores(Complexo valores[2]) {
	for(int i = 0; i < 2; i++) {
		if(valores[i].z < 0) {
			valores[i].z = valores[i].z * -1;
		}
		if(valores[i].w < 0) {
			valores[i].w = valores[i].w * -1;
		}
		printf("Z%d = %.2f %.2fi\n", i + 1, valores[i].z, valores[i].w);
	}
}
