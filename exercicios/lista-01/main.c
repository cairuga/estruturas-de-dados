#include <stdio.h>
#include "lib.h"

int main(int argc, char *argv[]) {
	
	int quantidade;
	
	printf("Informe a quantidade de alunos: ");
	scanf("%d", &quantidade);
	
	float notas[quantidade];
	
	for (int i=0; i<quantidade; i++) {
		printf("Informe a nota do aluno %d: ", i+1);
		scanf("%f", &notas[i]);
	}	
	
	printf("Vetor original: ");
	imprimir(notas, quantidade, 0);	
	
	printf("Após ordenar(): ");
	ordenar(notas, quantidade);	
	imprimir(notas, quantidade, 0);
	
	printf("Após embaralhar(): ");
	embaralhar(notas, quantidade);	
	imprimir(notas, quantidade, 0);
	
	printf("Após ordenar_rec(): ");
	ordenar_rec(notas, quantidade);
	imprimir(notas, quantidade, -1);
	
	return 0;
}
