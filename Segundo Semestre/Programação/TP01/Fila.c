#include "Fila.h"
#include <stdio.h>
#include <stdlib.h>

#define CAPACIDADE_INICIAL 10

struct fila {
  int tamanho;
  int capacidade_maxima;
  Aluno *fila_alunos;
};

/* Aloca espaço em memória e retorna uma fila */
Fila *fila_cria() {
  Fila *fila = (Fila *)malloc(sizeof(Fila));
  fila->fila_alunos = (Aluno *)malloc(CAPACIDADE_INICIAL * sizeof(Aluno *));
  fila->capacidade_maxima = CAPACIDADE_INICIAL;
  fila->tamanho = 0;
  return fila;
}

/* Libera a memória de uma fila previamente criada e atribui NULL ao ponteiro
 * fila. Retorna 1 caso seja possível fazer a liberação e 0 caso a fila
 * informada seja NULL. */
int fila_libera(Fila **fila) {
  if (fila != NULL) {
    if ((*fila)->tamanho > 0) {
      free((*fila)->fila_alunos);
      (*fila)->fila_alunos = NULL;
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
  if((fila == NULL) || (aluno == NULL)){ //caso um dos parâmetros seja nulo
    return -1;
  }
  
  for(int i = 0; i <= fila->tamanho; i++){ //loop que percorre toda a lista
    if(fila->fila_alunos[i].matricula == aluno->matricula){ //verifica se já existe nos alunos da lista, algum com a mesma matrícula do aluno passado por parâmetro.
      return 0;
    }
  }
  if(fila->tamanho <= fila->capacidade_maxima){
    int tamanho = fila->tamanho;
    fila->tamanho++;
    fila->fila_alunos[tamanho] = *aluno;
    return 1;
  }
  return 2;
}

/* Remove um aluno na fila. Retorna o aluno ou NULL caso a fila esteja vazia ou
 * seja NULL */
Aluno *fila_retira(Fila *fila) {
  int tamanho = fila->tamanho;
  if((fila == NULL) || (tamanho == 0)){ //verifica se a fila está vazia 
    return NULL;
  }
  Aluno* aluno_retirado = (&(fila->fila_alunos))[tamanho]; //variavel que guarda o endereço de memória do aluno retirado
  alu_libera(fila->fila_alunos[tamanho]);
  fila->tamanho--;
  return aluno_retirado;
}

/* Recupera o primeiro aluno da fila. Retorna o aluno ou NULL caso a fila esteja
 * vazia ou seja NULL */
Aluno *fila_primeiro(Fila *fila) {
  if (fila == NULL || fila->tamanho == 0) {
    return NULL;
  }
  return (&(fila->fila_alunos))[0];
}

/* Busca aluno pelo número de matricula. Retorna o aluno se este estiver na
 * lista e NULL caso contrário, isto é, (i) fila vazia; (ii) não exista aluno
 * com a matricula fornecida; ou (iii) a fila seja NULL */
Aluno *fila_busca(Fila *fila, int matricula) {
  if((fila == NULL) || (fila->tamanho == 0)){
    return NULL;
  }
  for(int i = 0; i <= fila->tamanho; i++){
    if(fila->fila_alunos[i].matricula == matricula){
      return (&(fila->fila_alunos))[i];
    }
  }
  return NULL;
}

/* Verifica se a fila está vazia. Retorna 1 se a fila estiver vazia, 0 caso não
 * esteja vazia e -1 se a fila for NULL
 */
int fila_vazia(Fila *fila) {
  if (fila == NULL) {
    return -1;
  }
  if (fila->tamanho == 0) {
    return 1;
  }
  return 0;
}

/* Computa a quantidade de alunos alunos na fila. Retorna a quantidade de alunos
 * ou -1, caso a fila for NULL.
 */
int fila_quantidade(Fila *fila) {
  if (fila == NULL) {
    return -1;
  }

  return fila->tamanho;
}