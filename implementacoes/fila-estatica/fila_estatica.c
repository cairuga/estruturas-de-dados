#include <stdio.h>
#include <stdlib.h>
#include "fila_estatica.h"

Fila* criar_fila(){
   // Aloca memória para a fila
   Fila* fila = (Fila*) malloc(sizeof(Fila));
   
   // Verifica se a alocação foi bem-sucedida
   if (fila == NULL){
      printf("Erro ao alocar memória para a fila!\n");
      return NULL; // Retorna NULL se a alocação falhar
   }
   // Inicializa os índices (início e fim) e o tamanho da fila
   fila->inicio = 0;
   fila->fim = 0;
   fila->tamanho = 0;

   // Retorna o ponteiro para a fila criada
   return fila;
}

int fila_vazia(Fila* fila){
   // Verifica se a fila existe
   if (fila == NULL)
      return -1; // retorna -1 indicando erro caso a fila não exista!
   
   // Verifica se o tamanho da fila é zero
   if (fila->tamanho == 0)
      return 1; // retorna 1 (true) se a fila estiver vazia
   else
      return 0; // retorna 0 (false) se a fila não estiver vazia
}

int fila_cheia(Fila* fila){
   // Verifica se a fila existe
   if (fila == NULL)
      return -1; // retorna -1 indicando erro caso a fila não exista!
   
   // Verifica se o tamanho da fila é igual ao máximo permitido
   if (fila->tamanho == MAX)
      return 1; // retorna 1 (true) se a fila estiver cheia
   else
      return 0; // retorna 0 (false) se a fila NÃO estiver cheia
}

int inserir_fila(Fila* fila, Pessoa pessoa){
   // Verifica se a fila existe
   if (fila == NULL)
      return -1; // retorna -1 indicando erro caso a fila não exista!

   if (fila_cheia(fila)) { // verifica se a fila está cheia
      printf("Fila cheia! Não é possível inserir %s.\n", pessoa.nome);
      return 0; // retorna 0 (false) se a fila estiver cheia, indicando que a inserção falhou
   }
   // Insere a pessoa no fim da fila
   // Nessa implementação, o ponteiro 'fim' aponta para posição onde o próximo elemento será inserido
   // ou seja, ele não aponta para o último elemento da fila, mas sim para a próxima posição disponível
   fila->dados[fila->fim] = pessoa;

   // Atualiza o índice 'fim' para a próxima posição 
   // Note que o índice 'fim' é circular, ou seja, ele volta ao início quando atinge o tamanho máximo
   // Isso é feito usando o operador módulo (%), que garante que o índice fique dentro dos limites do vetor
   fila->fim = (fila->fim + 1) % MAX;
   
   // Incrementa o tamanho da fila, mantendo o controle do número de elementos na fila
   fila->tamanho++;

   return 1; // retorna 1 (true) indicando que a inserção foi bem-sucedida
}

Pessoa* consultar_fila(Fila* fila){
   // Verifica se a fila é nula ou está vazia
   if(fila == NULL || fila_vazia(fila))
      return NULL;

   // Retorna o endereço do primeiro elemento da fila
   return &fila->dados[fila->inicio];
}

int remover_fila(Fila* fila){
   // Verifica se a fila é nula ou está vazia
   if(fila == NULL || fila_vazia(fila))
      return 0; // retorna 0 (false) indicando que a remoção falhou

   // Atualiza o índice do 'inicio' para remover o primeiro elemento
   fila->inicio = (fila->inicio + 1) % MAX;
   // Não precisamos liberar a memória do elemento removido, pois a fila é estática
   // Não precisamos limpar o conteúdo do elemento, os índicew de inicio e fim o mantem fora da fila
   // Também não precisamos mover os elementos restantes, pois a fila é circular
   // O operador módulo (%) garante que o índice fique dentro dos limites do vetor
   // Assim, quando o índice 'inicio' atinge o tamanho máximo, ele volta para o início do vetor
   
   // Decrementa o tamanho da fila, mantendo o controle do número de elementos na fila
   fila->tamanho--;

   return 1; // retorna 1 (true) indicando que a remoção foi bem-sucedida
}

void liberar_fila(Fila* fila){
   // libera a memória alocada para a fila
   free(fila);
}

// Esse método imprime todos os elementos da fila, do primeiro ao último
// Ele percorre a fila circular e imprime os dados de cada pessoa
// Ele está muito acoplado aos tipos de dados definidos, dependendo das estruturas da fila e dos dados armazenados nela
void imprimir_fila(Fila* fila) {
   // Verifica se a fila existe
   if(fila == NULL) {
      printf("\nA fila não existe!\n");
      return;
   }

   // Verifica se a fila está vazia
   if(fila_vazia(fila)) {
      printf("\nA fila está vazia!\n");
      return;
   }

   // Imprime o cabeçalho da fila  
   printf("\nFila de Pessoas: \n");


   // Percorre cada um dos n elementos da fila, começando pelo 'inicio'
   int contador;
   int indice = fila->inicio;
   for (contador=0; contador < fila->tamanho; contador++){
      // Imprime os dados da pessoa na posição 'indice'
      printf("%d - Nome: %s | Idade: %d\n", contador + 1, fila->dados[indice].nome, fila->dados[indice].idade);

      // Atualiza o índice para a próxima posição circular
      indice = (indice + 1) % MAX;
   }
}
