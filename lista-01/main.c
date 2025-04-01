#include <stdio.h>
#include "lista_estatica.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	//criando uma nova lista
	Lista* lista = criar_lista();
	
	//inserindo o primeiro elemento
	inserir(10, 0, lista);	// Lista: 10
	
	//inserindo no iníico da lista (posição 0)
	inserir(17, 0, lista);	// Lista: 17 10
	inserir(32, 0, lista);	// Lista: 32 17 10
	inserir(9, 0, lista);	// Lista: 09 32 17 10
	
	//inserindo no final da lista (posição tamanho)
	inserir(43, lista->tamanho, lista);	// Lista: 09 32 17 10 43
	inserir(60, lista->tamanho, lista);	// Lista: 09 32 17 10 43 60
	inserir(18, lista->tamanho, lista);	// Lista: 09 32 17 10 43 60 18
	
	//inserindo em posições específicas posição específica
	inserir(28, 1, lista);	// Lista: 09 28 32 17 10 43 60 18
	inserir(51, 4, lista);	// Lista: 09 28 32 17 51 10 43 60 18
	
	//removendo do início (posição 0);
	remover(0, lista); // Lista: 28 32 17 51 10 43 60 18
	
	//removendo do final (posição tamanho-1)
	remover(lista->tamanho-1, lista); // Lista: 28 32 17 51 10 43 60
	
	//removendo de uma posição específica
	remover(4, lista); // Lista: 28 32 17 51 43 60
	
	//substituindo um elemento
	substituir(64, 5, lista); // Lista: 28 32 17 51 43 64
	
	//imprimindo a lista
	imprimir(lista); // Lista: 28 32 17 51 43 64
	
	//verificando o tamanho da lista
	printf("Tamanho atual: %d\n", lista->tamanho); // Tamanho atual: 6

	
	//verificando se a lista está cheia
	printf("Lista cheia? %d\n", lista_cheia(lista)); // Lista cheia? 0
	
	//verificando se a lista está vazia
	printf("Lista vazia? %d\n", lista_vazia(lista)); // Lista vazia? 0
	
	//procurando elementos
	printf("Posição do elemento 51: %d\n", procurar(51, lista)); // Posição do elemento 51: 3
	printf("Posição do elemento 80: %d\n", procurar(80, lista)); // Posição do elemento 51: -1
	
	return 0;
}
