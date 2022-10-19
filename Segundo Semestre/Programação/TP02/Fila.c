#include "Fila.h"
#include <stdio.h>
#include <stdlib.h>

struct node {
  Aluno *aluno;
  struct node *proximo;
};

typedef struct node No;

struct fila {
  No *primeiro;
  int tamanho;
};

/* Aloca espaço em memória e retorna uma fila */
Fila *fila_cria() {
  Fila *fila = (Fila *)malloc(sizeof(Fila));
  fila->primeiro = NULL;
  fila->tamanho = 0;
  return fila;
}

/* Libera a memória de uma fila previamente criada e atribui NULL ao ponteiro
 * fila. Retorna 1 caso seja possível fazer a liberação e 0 caso a fila
 * informada seja NULL. */
int fila_libera(Fila **fila) {
  if (fila != NULL) {
    if ((*fila)->primeiro != NULL) {
      No *aux = (*fila)->primeiro;
      do {
        alu_libera(&aux->aluno);
        aux = aux->proximo;
      } while (aux != NULL);
    }
    free(*fila);
    *fila = NULL;
    return 1;
  }
  return 0;
}

/* Insere um aluno na fila. Retorna 1 se foi possível adicionar, 0 caso já
 * exista um aluno com a mesma matricula (nesse caso, o aluno não pode ser
 * adicionado) e -1 caso a fila ou aluno sejam NULL
 */
int fila_insere(Fila *fila, Aluno *aluno) {
  if (aluno == NULL || fila == NULL) {
    return-1;
  }

  //Cria o novo nó que será inserido na fila, e o preenche com os valores passados por parâmetro.
  No novoNo;
  novoNo.aluno = aluno;
  novoNo.proximo = NULL;
  No** enderecoNoComparado = (&(fila -> primeiro));
  No* noComparado = fila -> primeiro;
  
  if(noComparado == NULL){ //se o primeiro no da fila for nulo, ou seja, fila vazia
    fila -> primeiro = &novoNo;
    fila -> tamanho++;
    return 1;
  }
  
  int matFixa;
  char nomeFixo[50];
  char cursoFixo[30];
  
  int matricula;
  char nome[50];
  char curso[30];
  
  alu_acessa(aluno, &matFixa, nomeFixo, cursoFixo); //atribui as variaveis passadas na função, os valores dos campos de aluno.
  
  while(noComparado->proximo != NULL){ //enquanto o nó apontar para um próximo, ou seja, enquanto o nó comparado não seja o último nó da fila.
    noComparado = *enderecoNoComparado;
    No *proximo = noComparado->proximo;
    alu_acessa(proximo->aluno, &matricula, nome, curso); //acessa os valores do aluno do próximo nó
  
        if (matricula == matFixa) {
          return 0;
        }
  
    enderecoNoComparado = (&(noComparado->proximo)); //pula para o próximo nó.
  }
  noComparado->proximo = &novoNo; //o nó que antes era o ultimo da fila, agora aponta para o novo nó criado.
  fila->tamanho++;
  return 1;
}

/* Recupera o primeiro aluno da fila. Retorna o aluno ou NULL caso a fila esteja
 * vazia ou seja NULL */
Aluno *fila_primeiro(Fila *fila) {
/*  if(fila == NULL){
    return NULL;
  }
  No* primeiroNo = fila->primeiro;
  Aluno* primeiroAluno = primeiroNo -> aluno;
  return primeiroAluno;*/
  return NULL;
}

/* Remove um aluno na fila. Retorna o aluno ou NULL caso a fila esteja vazia ou
 * seja NULL */
Aluno *fila_retira(Fila *fila) {
  if(fila == NULL || fila->primeiro == NULL){
    return NULL;
  }
  Aluno *primeiroAluno = fila_primeiro(fila);
  fila->primeiro = *(&(fila->primeiro->proximo));
  fila->tamanho--;
  return primeiroAluno;
}

/* Busca aluno pelo número de matricula. Retorna o aluno se este estiver na
 * lista e NULL caso contrário, isto é, (i) fila vazia; (ii) não exista aluno
 * com a matricula fornecida; ou (iii) a fila seja NULL */
Aluno *fila_busca(Fila *fila, int matricula) {
  int matFixa;
  char nomeFixo[50];
  char cursoFixo[30];
  No **enderecoNoAtual = (&(fila->primeiro));
  No *noAtual;

  alu_acessa(fila_primeiro(fila), &matFixa, nomeFixo, cursoFixo);

  while(matFixa != matricula){
    noAtual = *enderecoNoAtual;
    alu_acessa(noAtual->proximo->aluno, &matFixa, nomeFixo, cursoFixo);
    enderecoNoAtual = (&(noAtual -> proximo));
  }

  return noAtual -> aluno;
}

/* Verifica se a fila está vazia. Retorna 1 se a fila estiver vazia, 0 caso não
 * esteja vazia e -1 se a fila for NULL
 */
int fila_vazia(Fila *fila) {
  if(fila == NULL){
    return -1;
  }else if(fila -> primeiro == NULL){
    return 1;
  }else{
    return 0;
  }
}

/* Computa a quantidade de alunos alunos na fila. Retorna a quantidade de alunos
 * ou -1, caso a fila for NULL.
 */
int fila_quantidade(Fila *fila) {
  return fila->tamanho;
}