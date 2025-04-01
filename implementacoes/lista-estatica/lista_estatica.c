#include <stdlib.h>
#include <stdio.h>
#include "lista_estatica.h"

Lista* criar_lista() {
	Lista *lista;
	lista = (Lista*) malloc(sizeof(Lista));
	if (lista != NULL) lista->tamanho = 0;
	return lista;
}

Lista* liberar_lista(Lista* lista) {
	free(lista);
	lista = NULL;	
	return lista;
}

int lista_cheia(Lista* lista) {
	if (lista == NULL) return -1;
	return (lista->tamanho == MAX);
}

int lista_vazia(Lista* lista) {
	if (lista == NULL) return -1;
	return (lista->tamanho == 0);
}

int inserir(Item item, int posicao, Lista* lista) {
	if (lista == NULL || lista_cheia(lista)) return 0;	
	if (posicao > lista->tamanho || posicao < 0) return 0;	
	for (int i=lista->tamanho; i>posicao;i--){
		lista->itens[i]=lista->itens[i-1];
	}	
	lista->itens[posicao] = item;	
	lista->tamanho += 1;	
	return 1;		
}

int remover(int posicao, Lista* lista) {		
	if (lista == NULL) return 0;
	if (posicao > lista->tamanho - 1 || posicao < 0) return 0;	
	for (int i=posicao; i<lista->tamanho-1;i++){
		lista->itens[i]=lista->itens[i+1];
	}	
	lista->tamanho -= 1;	
	return 1;		
}

int substituir(Item item, int posicao, Lista* lista) {	
	if (lista == NULL) return 0;	
	if (posicao > lista->tamanho-1 || posicao < 0) return 0;	
	lista->itens[posicao] = item;	
	return 1;		
}

void imprimir(Lista* lista) {
	if (lista == NULL) return;
    printf("Lista: ");
	for (int i=0; i<lista->tamanho; i++) {
		// essa rotina deve ser personalizada
		// conforme o tipo de dados do elemento		
		printf("%d ", lista->itens[i]);
	}
	printf("\n");
}

int procurar(Item item, Lista* lista) {
	if (lista == NULL) return -1;
	for (int i=0; i<lista->tamanho; i++) {		
		// essa rotina deve ser personalizada
		// conforme o tipo de dados do elemento
		if (lista->itens[i]==item) return i;
	}
	return -1;		
}
