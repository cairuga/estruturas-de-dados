#include <stdio.h>
#include <stdlib.h>
#include "lista_dup_encadeada.h"

Lista* criar_lista() {
   Lista* lista = (Lista*) malloc(sizeof(Lista));
   if (lista != NULL) {
      lista->inicio = NULL;
      lista->fim = NULL;
   }
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
   novo->anterior = NULL;
   novo->proximo = lista->inicio;

   if (lista->inicio != NULL)
      lista->inicio->anterior = novo; 
   else
      lista->fim = novo;

   lista->inicio = novo;
   return 1;
}

int inserir_fim(int valor, Lista* lista) {
   if (lista == NULL) return 0;

   Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
   if (novo == NULL) return 0;

   novo->valor = valor;
   novo->proximo = NULL;
   novo->anterior = lista->fim;

   if (lista->fim != NULL)
       lista->fim->proximo = novo;
   else
       lista->inicio = novo;

   lista->fim = novo;
   return 1;
}

int remover_inicio(Lista* lista) {
   if (lista == NULL || lista->inicio == NULL) return 0;

   Elemento* removido = lista->inicio;
   lista->inicio = lista->inicio->proximo;

   if (lista->inicio != NULL)
       lista->inicio->anterior = NULL;
   else
       lista->fim = NULL;

   free(removido);
   return 1;
}

int remover_fim(Lista* lista) {
   if (lista == NULL || lista->fim == NULL) return 0;

   Elemento* removido = lista->fim;
   lista->fim = lista->fim->anterior;

   if (lista->fim != NULL)
       lista->fim->proximo = NULL;
   else
       lista->inicio = NULL;

   free(removido);
   return 1;
}

void imprimir(Lista* lista) {
   if (lista == NULL || lista->inicio == NULL) {
       printf("Lista vazia.\n");
       return;
   }

   Elemento* atual = lista->inicio;
   printf("Lista: ");
   while (atual != NULL) {
       printf("%d ", atual->valor);
       atual = atual->proximo;
   }
   printf("\n");
}

void imprimir_reverso(Lista* lista) {
   if (lista == NULL || lista->fim == NULL) {
       printf("Lista vazia.\n");
       return;
   }

   Elemento* atual = lista->fim;
   printf("Reverso: ");
   while (atual != NULL) {
       printf("%d ", atual->valor);
       atual = atual->anterior;
   }
   printf("\n");
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
