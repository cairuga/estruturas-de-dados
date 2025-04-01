#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// se o parâmetro ordem for negativo, imprime na ordem inversa!
void imprimir(float vetor[], int n, int ordem){
	if (ordem >= 0) {
		for (int i=0; i<n; i++) {
			printf("%.1f ", vetor[i]);
		}	
	} else {
		for (int i=n-1; i>=0; i--) {
			printf("%.1f ", vetor[i]);
		}		
	}	
	printf("\n");
}
  
void embaralhar(float vetor[], int n) {
	srand(time(NULL));
	for (int i=n-1; i>0; i--) {
		int j = rand() % (i + 1);
		float temp = vetor[i];
		vetor[i] = vetor[j];
		vetor[j] = temp;
	}
}

void ordenar(float vetor[], int n) {  
	for (int i=0; i<n-1; i++) {
		int swapped = 0;
		for (int j=0; j<n-i-1; j++) {
			if (vetor[j] > vetor[j + 1]) {
				float temp = vetor[j];
				vetor[j] = vetor[j + 1];
				vetor[j + 1] = temp;
				swapped = 1;
			}
		}
		if (swapped == 0) break;
	}
}


/* Poderia ser feito sem a otimização com o swapped
void ordenar(float vetor[], int n) {  
	for (int i=0; i<n-1; i++) {
		for (int j=0; j<n-i-1; j++) {
			if (vetor[j] > vetor[j + 1]) {
				float temp = vetor[j];
				vetor[j] = vetor[j + 1];
				vetor[j + 1] = temp;
			}
		}
	}
} */


void ordenar_rec(float vetor[], int n){ 
	if (n < 1) return;  	
	for (int i=0; i<n-1; i++) {
		if (vetor[i] > vetor[i+1]) {
			float temp = vetor[i];
			vetor[i] = vetor[i+1];
			vetor[i+1] = temp;
		}
	}
	ordenar_rec(vetor, n-1); 
}
