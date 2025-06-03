#ifndef FILA_ESTATICA_H
#define FILA_ESTATICA_H

// DEFINE O TAMANHO MÁXIMO DA FILA
#define MAX 5

// DEFINE O TIPO DE DADO ARMAZENADO NA FILA
typedef struct pessoa{
	char nome[30];
   int idade;
} Pessoa;

// DEFINE A ESTRUTURA DA FILA
typedef struct fila{
	int inicio; // indice da posição do primeiro elemento da fila
   int fim; // indice da posição do último elemento da fila
   int tamanho; // quantidade de elementos na fila
	Pessoa dados[MAX]; // vetor de pessoas que compõe a fila
} Fila;

// IMPORTANTE:

// O ponteiro 'inicio' aponta para a posição do primeiro elemento da fila.
// Acessamos a fila através desse ponteiro quando queremos consultar ou remover o primeiro elemento da fila.
// Se a fila possuir elementos, o ponteiro 'inicio' sempre apontará para a posição do primeiro elemento.

// O ponteiro 'fim' não aponta para um elemento da fila, mas sim para a posição onde o próximo elemento será inserido.
// Usamos esse ponteiro para inserir novos elementos na fila, sempre ao final, na primeira posição disponível.

// Quando a fila está vazia, tanto 'inicio' quanto 'fim' apontam para a mesma posição, 
// que é a posição 0 do vetor. Nesse caso, o tamanho da fila é zero, ou seja, não há elementos na fila.

// A fila é implementada como um vetor circular, ou seja, quando o ponteiro 'fim' atinge o tamanho máximo da fila,
// ele volta para o início do vetor, permitindo que a fila utilize todo o espaço disponível de forma eficiente.

// A fila é estática, ou seja, seu tamanho é fixo e definido pelo valor da constante MAX.
// Portanto, não é possível aumentar ou diminuir o tamanho da fila durante a execução do programa.


// PROTÓTIPOS DAS FUNÇÕES
Fila* criar_fila(void); // cria uma fila vazia
void liberar_fila(Fila* fila); // libera a memória alocada para a fila
Pessoa* consultar_fila(Fila* fila); // consulta o primeiro elemento da fila
int inserir_fila(Fila* fila, Pessoa pessoa); // insere uma pessoa no fim da fila
int remover_fila(Fila* fila); // remove a primeira pessoa da fila
int fila_vazia(Fila* fila); // verifica se a fila está vazia
int fila_cheia(Fila* fila); // verifica se a fila está cheia
void imprimir_fila(Fila* fila); // imprime todos os pessoas da fila

#endif
