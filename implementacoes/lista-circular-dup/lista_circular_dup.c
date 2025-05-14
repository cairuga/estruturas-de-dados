#include <stdio.h>
#include <stdlib.h>
#include "lista_circular_dup.h"

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

    if (lista->inicio == NULL) {
        novo->proximo = novo;
        novo->anterior = novo;
        lista->inicio = novo;
        lista->fim = novo;
    } else {
        novo->proximo = lista->inicio;
        novo->anterior = lista->fim;

        lista->fim->proximo = novo;
        lista->inicio->anterior = novo;

        lista->inicio = novo;
    }

    return 1;
}

int inserir_fim(int valor, Lista* lista) {
    if (lista == NULL) return 0;

    Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
    if (novo == NULL) return 0;

    novo->valor = valor;

    if (lista->fim == NULL) {
        novo->proximo = novo;
        novo->anterior = novo;
        lista->inicio = novo;
        lista->fim = novo;
    } else {
        novo->proximo = lista->inicio;
        novo->anterior = lista->fim;

        lista->fim->proximo = novo;
        lista->inicio->anterior = novo;

        lista->fim = novo;
    }

    return 1;
}

int remover_inicio(Lista* lista) {
    if (lista == NULL || lista->inicio == NULL) return 0;

    Elemento* removido = lista->inicio;

    if (lista->inicio == lista->fim) {
        lista->inicio = NULL;
        lista->fim = NULL;
    } else {
        lista->inicio = removido->proximo;
        lista->inicio->anterior = lista->fim;
        lista->fim->proximo = lista->inicio;
    }

    free(removido);
    return 1;
}

int remover_fim(Lista* lista) {
    if (lista == NULL || lista->fim == NULL) return 0;

    Elemento* removido = lista->fim;

    if (lista->inicio == lista->fim) {
        lista->inicio = NULL;
        lista->fim = NULL;
    } else {
        lista->fim = removido->anterior;
        lista->fim->proximo = lista->inicio;
        lista->inicio->anterior = lista->fim;
    }

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
    do {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    } while (atual != lista->inicio);
    printf("\n");
}

void imprimir_reverso(Lista* lista) {
    if (lista == NULL || lista->fim == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    Elemento* atual = lista->fim;
    printf("Reverso: ");
    do {
        printf("%d ", atual->valor);
        atual = atual->anterior;
    } while (atual != lista->fim);
    printf("\n");
}

void liberar_lista(Lista* lista) {
    if (lista == NULL || lista->inicio == NULL) return;

    Elemento* atual = lista->inicio;
    do {
        Elemento* temp = atual;
        atual = atual->proximo;
        free(temp);
    } while (atual != lista->inicio);

    free(lista);
}

int tamanho(Lista* lista) {
    if (lista == NULL || lista->inicio == NULL) return -1;

    int contador = 0;
    Elemento* atual = lista->inicio;
    do {
        contador++;
        atual = atual->proximo;
    } while (atual != lista->inicio);
    return contador;
}
