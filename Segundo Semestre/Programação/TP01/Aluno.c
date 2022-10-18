#include "Aluno.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct aluno {
  int matricula;
  char nome[50];
  char curso[30];
};

int verifica_tamanho(char *nome, char *curso){
  if (strlen(nome) > 30 || strlen(curso) > 50){ //verificação do tamanho das strings. Se um dos campos for maior do que o limite, será retornado 1.
    return 1;
  } 
  return 0; //os campos estão dentro do limite de tamanho.
}

int verifica_nulidade(char *nome, char *curso, int matricula){
  if(matricula == -1 || nome == NULL || curso == NULL){
    return 1; //algum dos campos está com valores inválidos, então será retornado 1.
  }
  return 0; //não foi detectado nulidades.
}

/* Aloca e retorna um aluno com os dados passados por parâmetro. Porém, para os
 * casos em que (i) pelo menos um dos parâmetros sejam nulos <-1, NULL, NULL>; e
 * (ii) o tamanho das strings nome e curso sejam maiores que os da especificação
 * (50 e 30, respectivamente), a função deve retornar NULL. */
Aluno *alu_novo(int matricula, char *nome, char *curso) {
  if (verifica_nulidade(nome, curso, matricula) == 1){ //verificação do tamanho das strings.
    return NULL;
  }
  
  if (verifica_tamanho(nome, curso) == 1) { //verificação de nulidade dos campos
    return NULL;
  } 

  Aluno *aluno = (Aluno *) malloc(sizeof(Aluno)); //aloca o novo aluno.
  aluno -> matricula = matricula;
  strcpy(aluno -> nome, nome); //destino, fonte.
  strcpy(aluno -> curso, curso);

  return aluno;
}

/* Libera a memória de um aluno previamente criado e atribui NULL ao aluno. */
void alu_libera(Aluno **aluno){
  free(*aluno);
  *aluno = NULL;
}

/* Copia os valores de um aluno para as referências informadas. Em caso de aluno
 * NULL, atribuir valor padrão <-1, "NULL", "NULL"> aos parâmetros. */
void alu_acessa(Aluno *aluno, int *matricula, char *nome, char *curso){
  if(aluno == NULL){
    *matricula = -1;
    nome = NULL;
    curso = NULL;
  }
  
  *matricula = aluno -> matricula;
  strcpy(nome, aluno -> nome);
  strcpy(curso, aluno -> curso);

}

/* Atribui novos valores aos campos de um aluno. Porém, para os casos em que (i)
 * algum dos parâmetros sejam nulos <NULL, -1, NULL, NULL>; ou (ii) o tamanho
 * das strings nome e curso sejam maiores que os da especificação (50 e 30,
 * respectivamente), a função não deve fazer a atribuição. */
void alu_atribui(Aluno *aluno, int matricula, char *nome, char *curso){
  if((verifica_nulidade(nome, curso, matricula) == 0) && (verifica_tamanho(nome, curso) == 0)){ // as atribuições só são realizadas se as verificações de nulidade e tamanho retornarem falso.
    aluno -> matricula = matricula;
    strcpy(aluno -> nome, nome);
    strcpy(aluno -> curso, curso);
  }
}

/* Avalia se dois alunos são iguas. A função deve retornar 1 se os alunos
 * possuem os mesmos dados, 0 caso os dados dos alunos possuam alguma diferença
 * e -1 caso pelo menos um dos alunos seja NULL.
 */
int alu_igual(Aluno *aluno1, Aluno *aluno2){
  if(aluno1 == NULL || aluno2 == NULL){
    return -1;
  }
  if(strcmp(aluno1 -> nome, aluno2 -> nome) != 0){ //retorna 0 se os nomes forem diferentes.
    return 0;
  } 
  if(strcmp(aluno1 -> curso, aluno2 -> curso) != 0){ //retorna 0 se os cursos forem diferentes.
    return 0;
  } 
  if(aluno1 -> matricula != aluno2 -> matricula){ //retorna 0 se as matriculas forem diferentes.
    return 0;
  } 

  return 1;
}

/* Retorna o tamanho em bytes do TAD aluno. */
int alu_tamanho(){
  return sizeof(Aluno);
}
