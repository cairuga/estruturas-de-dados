#ifndef LISTA_ESTATICA_H  // Verifica se ainda não foi definido
#define LISTA_ESTATICA_H  // Define o identificador

#define MAX 50

typedef int Item;

typedef struct {
   int tamanho;
   Item itens[MAX];
} Lista;

Lista* criar_lista();

Lista* liberar_lista(Lista* lista);

int lista_cheia(Lista* lista);

int lista_vazia(Lista* lista);

int inserir(Item item, int posicao, Lista* lista);

int remover(int posicao, Lista* lista);

int substituir(Item item, int posicao, Lista* lista);

void imprimir(Lista* lista);

int procurar(Item item, Lista* lista);

#endif // Fim do include guard
