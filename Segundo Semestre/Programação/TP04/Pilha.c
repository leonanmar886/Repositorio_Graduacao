#include "Pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAPACIDADE_INICIAL 10

struct node {
  Aluno *aluno;
  struct node *proximo;
};

typedef struct node No;

struct pilha {
  No *primeiro;
  int tamanho;
};

/* Aloca espaço em memória e retorna uma pilha. */
Pilha *pilha_cria() {
  Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
  pilha->primeiro = NULL;
  pilha->tamanho = 0;
  return pilha;
}

/* Libera a memória de uma pilha previamente criada e atribui NULL ao ponteiro
 * pilha. Retorna 1 caso seja possível fazer a liberação e 0 caso a pilha
 * informada seja NULL. */
int pilha_libera(Pilha **pilha) {
  if (pilha != NULL) {
    if ((*pilha)->primeiro != NULL) {
      No *aux = (*pilha)->primeiro;
      do {
        alu_libera(&aux->aluno);
        aux = aux->proximo;
      } while (aux != NULL);
    }
    free(*pilha);
    *pilha = NULL;
    return 1;
  }
  return 0;
}

/* Insere um aluno na Pilha. Retorna 1 se foi possível adicionar, 0 caso já
 * exista um aluno com a mesma matricula (nesse caso, o aluno não pode ser
 * adicionado) e -1 caso a pilha ou aluno sejam NULL.
 */
int pilha_push(Pilha *pilha, Aluno *aluno) {
  if (pilha == NULL || aluno == NULL) {
    return -1;
  }

  if (pilha->primeiro == NULL) {
    No *novoNo = (No *)malloc(sizeof(No));
    novoNo->aluno = aluno;
    novoNo->proximo = NULL;
    No **enderecoNoComparado = &(pilha->primeiro);
    *enderecoNoComparado = novoNo;
    pilha->tamanho++;
    return 1;
  }

  int matFixa;
  char nomeFixo[50];
  char cursoFixo[30];

  int matricula;
  char nome[50];
  char curso[30];

  alu_acessa(aluno, &matFixa, nomeFixo,
             cursoFixo); // atribui as variaveis passadas na função, os valores
                         // dos campos de aluno.

  No *noAtual = pilha->primeiro;
  No *noAnterior = noAtual;

  while (noAtual !=
         NULL) { // enquanto o nó apontar para um próximo, ou seja, enquanto o
                 // nó comparado não seja o último nó da pilha.
    alu_acessa(noAtual->aluno, &matricula, nome,
               curso); // acessa os valores do aluno do próximo nó

    if (matricula == matFixa) {
      return 0;
    }

    noAnterior = noAtual;
    noAtual = noAtual->proximo; // pula para o próximo nó.
  }

  No *novoNo = (No *)malloc(sizeof(No));
  novoNo->aluno = aluno;
  novoNo->proximo = NULL;
  No **enderecoNoComparado = &(noAnterior->proximo);
  *enderecoNoComparado = novoNo;
  pilha->tamanho++;
  return 1;
}

/* Remove um aluno na pilha. Retorna o aluno ou NULL caso a pilha esteja vazia
 * ou seja NULL. */
Aluno *pilha_pop(Pilha *pilha) {
  if (pilha == NULL || pilha->primeiro == NULL) {
    return NULL;
  }
  No *noAtual = pilha->primeiro;
  No *noAnterior = noAtual;
  No *noAnteriorAnterior = noAtual;
  while (noAtual != NULL) {
    noAnteriorAnterior = noAnterior;
    noAnterior = noAtual;
    noAtual = noAtual->proximo;
  }
  noAnteriorAnterior->proximo = NULL;
  return noAnterior->aluno;
}

/* Recupera o primeiro aluno da pilha. Retorna o aluno ou NULL caso a pilha
 * esteja vazia ou seja NULL. */
Aluno *pilha_top(Pilha *pilha) {
  if (pilha == NULL || pilha->primeiro == NULL) {
    return NULL;
  }
  No *noAtual = pilha->primeiro;
  No *noAnterior = noAtual;

  while (noAtual != NULL) { // enquanto o nó apontar para um próximo, ou seja, enquanto o
                 // nó comparado não seja o último nó da pilha.
    noAnterior = noAtual;
    noAtual = noAtual->proximo; // pula para o próximo nó.
  }
  return noAnterior->aluno;
}
/* Busca aluno pelo número de matricula. Retorna o aluno se este estiver na
 * lista e NULL caso contrário, isto é, (i) pilha vazia; (ii) não exista aluno
 * com a matricula fornecida; ou (iii) a pilha seja NULL */
Aluno *pilha_busca(Pilha *pilha, int matricula) {
  if (pilha_vazia(pilha) == 1 || pilha == NULL) {
    return NULL;
  }

  // criação de variáveis para receberem os valores do aluno criado
  int matriculaAluno;
  char nome[50];
  char curso[30];

  No *noAtual = pilha->primeiro;
  No *noAux = noAtual;

  while (noAtual != NULL) {
    alu_acessa(noAtual->aluno, &matriculaAluno, nome, curso); // acessando os dados de cada aluno de cada nó visitado
    if (matriculaAluno ==
        matricula) { // verifica se há matrícula igual a do aluno novo
      return noAtual->aluno;
    }
    noAux = noAtual;
    noAtual = noAtual->proximo;
  }

  return NULL;
}

/* Verifica se a pilha está vazia. Retorna 1 se a pilha estiver vazia, 0 caso
 * não esteja vazia e -1 se p Pilha for NULL
 */
int pilha_vazia(Pilha *pilha) {
  if (pilha == NULL) {
    return -1;
  }
  if (pilha->primeiro == NULL) {
    return 1;
  }
  return 0;
}

/* Computa a quantidade de alunos na pilha. Retorna a quantidade de alunos
 * ou -1, caso a Pilha for NULL.
 */
int pilha_quantidade(Pilha *pilha) { return pilha->tamanho; }