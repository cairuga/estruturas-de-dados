// lista.c

#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"

Lista* criar_lista() {
   Lista* lista = (Lista*) malloc(sizeof(Lista));
   if (lista != NULL) lista->inicio = NULL;
   return lista;
}

int lista_vazia(Lista* lista) {
   if (lista == NULL) return -1;
   return lista->inicio == NULL;
}

int inserir_inicio(int valor, Lista* lista) {
   if (lista == NULL) return 0;
   Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
   if (novo == NULL) return 0;
   novo->valor = valor;
   novo->proximo = lista->inicio;
   lista->inicio = novo;
   return 1;
}

int inserir_ordem(int valor, Lista* lista) {
   if (lista == NULL) return 0;
   Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
   if (novo == NULL) return 0;
   novo->valor = valor;

   if (lista->inicio == NULL || lista->inicio->valor > valor) {
      novo->proximo = lista->inicio;
      lista->inicio = novo;
      return 1;
   }

   Elemento* atual = lista->inicio;
   while (atual->proximo != NULL && atual->proximo->valor < valor) {
      atual = atual->proximo;
   }
   novo->proximo = atual->proximo;
   atual->proximo = novo;
   return 1;
}

int inserir_fim(int valor, Lista* lista) {
    if (lista == NULL) return 0;
    Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
    if (novo == NULL) return 0;
    novo->valor = valor;
    novo->proximo = NULL;

    if (lista->inicio == NULL) {
        lista->inicio = novo;
        return 1;
    }

    Elemento* atual = lista->inicio;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }
    atual->proximo = novo;
    return 1;
}

void imprimir(Lista* lista) {
   if (lista == NULL) return;
   printf("Lista: ");
   Elemento* atual = lista->inicio;
   while (atual != NULL) {
       printf("%d ", atual->valor);
       atual = atual->proximo;
   }
   printf("\n");
}

int remover_inicio(Lista *lista) {
   if (lista == NULL) return 0;
   if (lista->inicio == NULL) return 0;
   Elemento* primeiro = lista->inicio;
   lista->inicio = primeiro->proximo;
   free(primeiro);
   return 1;
}

int remover_fim(Lista* lista) {
    if (lista == NULL || lista->inicio == NULL) return 0;

    Elemento* atual = lista->inicio;
    Elemento* anterior = NULL;

    while (atual->proximo != NULL) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (anterior == NULL) {
        lista->inicio = NULL;
    } else {
        anterior->proximo = NULL;
    }

    free(atual);
    return 1;
}

int remover_valor(int valor, Lista* lista) {
    if (lista == NULL || lista->inicio == NULL) return 0;

    Elemento* atual = lista->inicio;
    Elemento* anterior = NULL;

    while (atual != NULL && atual->valor != valor) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) return 0;

    if (anterior == NULL) {
        lista->inicio = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    free(atual);
    return 1;
}

int tamanho(Lista* lista) {
    if (lista == NULL) return -1;

    int contador = 0;
    Elemento* atual = lista->inicio;
    while (atual != NULL) {
        contador++;
        atual = atual->proximo;
    }
    return contador;
}

Elemento* buscar(int valor, Lista* lista) {
   if (lista == NULL) return NULL;
   
   Elemento* atual = lista->inicio;
   while (atual != NULL) {
       if (atual->valor == valor) {
           return atual;
       }
       atual = atual->proximo;
   }
   return NULL;
}

void liberar_lista(Lista* lista) {
   if (lista == NULL) return;
   Elemento* atual = lista->inicio;
   while (atual != NULL) {
       Elemento* temp = atual;
       atual = atual->proximo;
       free(temp);
   }
   free(lista);
}
