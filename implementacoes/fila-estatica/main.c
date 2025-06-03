#include <stdio.h>
#include <stdlib.h>
#include "fila_estatica.h"
#include "locale.h"

int main(void) {
   setlocale(LC_ALL, "Portuguese");
   
   Fila* fila = criar_fila();

   printf("Inserindo Elesbão na fila...\n");
   Pessoa elesbao = {"Elesbão", 43};
   inserir_fila(fila, elesbao);

   printf("Inserindo Genoveva na fila...\n");
   Pessoa genoveva = {"Genoveva", 55};
   inserir_fila(fila, genoveva);

   printf("Inserindo Raoni na fila...\n");
   Pessoa raoni = {"Raoni", 27};
   inserir_fila(fila, raoni);

   imprimir_fila(fila);
   
   printf("\nRemovendo o primeiro da fila...\n");
   remover_fila(fila);
   
   Pessoa *proximo = consultar_fila(fila);
   if (proximo != NULL) {
      printf("Próximo da fila: %s, %d anos\n", proximo->nome, proximo->idade);
   } else { 
      printf("A fila está vazia!\n");
   }

   printf("\nInserindo Estela na fila...\n");
   Pessoa estela = {"Estela", 29};
   inserir_fila(fila, estela);

   imprimir_fila(fila);

   printf("\nInserindo Guilhermina na fila...\n");
   Pessoa guilhermina = {"Guilhermina", 34};
   inserir_fila(fila, guilhermina);

   printf("\nInserindo Múcio na fila...\n");
   Pessoa mucio = {"Múcio", 45};
   inserir_fila(fila, mucio);

   printf("\nInserindo Marvin na fila...\n");
   Pessoa marvin = {"Marvin", 9};
   inserir_fila(fila, marvin);

   imprimir_fila(fila);

   liberar_fila(fila);

   return 0;
}
