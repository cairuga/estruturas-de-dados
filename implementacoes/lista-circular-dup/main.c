#include <stdio.h>
#include "lista_dup_encadeada.h"

int main() {
   Lista* lista = criar_lista();

   inserir_inicio(10, lista);
   inserir_inicio(20, lista);
   inserir_inicio(30, lista);
   imprimir(lista);
   imprimir_reverso(lista);

   inserir_fim(40, lista);
   inserir_fim(50, lista);
   imprimir(lista);
   imprimir_reverso(lista);

   remover_inicio(lista);
   imprimir(lista);
   imprimir_reverso(lista);

   remover_fim(lista);
   imprimir(lista);
   imprimir_reverso(lista);

   printf("Tamanho: %d\n", tamanho(lista));
   
   liberar_lista(lista);

   return 0;
}
