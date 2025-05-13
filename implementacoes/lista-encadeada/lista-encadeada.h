#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

typedef struct elemento {
   int valor;
   struct elemento* proximo;
} Elemento;

typedef struct {
   Elemento* inicio;
} Lista;

// Funções da lista encadeada
Lista* criar_lista();
int lista_vazia(Lista* lista);
int inserir_inicio(int valor, Lista* lista);
int inserir_ordem(int valor, Lista* lista);
int inserir_fim(int valor, Lista* lista);
void imprimir(Lista* lista);
int remover_inicio(Lista *lista);
int remover_fim(Lista* lista);
int remover_valor(int valor, Lista* lista);
int tamanho(Lista* lista);
Elemento* buscar(int valor, Lista* lista);
void liberar_lista(Lista* lista);

#endif // LISTA_ENCADEADA_H
