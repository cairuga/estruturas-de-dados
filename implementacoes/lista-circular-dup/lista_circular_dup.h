#ifndef LISTA_CIRCULAR_DUP_H
#define LISTA_CIRCULAR_DUP_H

// Estrutura do elemento
typedef struct elemento {
   int valor;
   struct elemento* anterior;
   struct elemento* proximo;
} Elemento;

// Estrutura da lista
typedef struct {
   Elemento* inicio;
   Elemento* fim; 
} Lista;

// Funções da biblioteca
Lista* criar_lista();
int lista_vazia(Lista* lista);
int inserir_inicio(int valor, Lista* lista);
int inserir_fim(int valor, Lista* lista);
int remover_inicio(Lista* lista);
int remover_fim(Lista* lista);
void imprimir(Lista* lista);
void imprimir_reverso(Lista* lista);
void liberar_lista(Lista* lista);
int tamanho(Lista* lista);

#endif
