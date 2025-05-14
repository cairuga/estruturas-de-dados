#include <stdio.h>
#include "lista_encadeada.h"

int main() {
   Lista* lista = criar_lista();
   inserir_ordem(20, lista);
   inserir_ordem(33, lista);
   inserir_ordem(19, lista);
   imprimir(lista);           // Lista: 19 20 33 
   remover_inicio(lista);
   remover_fim(lista);
   inserir_fim(40, lista);
   inserir_fim(50, lista);
   inserir_ordem(45, lista);
   printf("Tamanho: %d\n", tamanho(lista)); // 4
   remover_valor(40, lista);
   imprimir(lista);           // Lista: 20 45 50
   liberar_lista(lista);
   return 0;
}
