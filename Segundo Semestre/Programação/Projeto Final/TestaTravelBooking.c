#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Passageiro.h"

int teste_passageiro_novo(){
  char nome1[50] = "Carlinhos";
  char endereco1[100] = "Rua Taquari, 3850";

  char nome2[50] = "89849384";
  char endereco2[100] = "75834578";

  Passageiro* passageiro1 = passageiro_novo(1, &nome1, &endereco1); // passageiro com dados válidos.
  Passageiro* passageiro2 = passageiro_novo(-1, &nome2, &endereco2); // passageiro com dados inválidos.
  Passageiro* passageiro3 = passageiro_novo(1, NULL, NULL); // passageiro com dados nulos,

  if(passageiro1 == NULL || passageiro2 != NULL || passageiro3 != NULL){
    printf("Falhou no teste de criação de passageiro.\n");
    return 0;
  }

  printf("Passou no teste de criação de passageiro.\n");
  return 1;
}

float teste_aluno_acessa_com_dados_validos() {
  int id;
  char nome[50];
  char endereco[100];

  Passageiro *passageiro = passageiro_novo(1, "Abraão", "Rua Taquari, 3850");
  if (passageiro != NULL) {
    passageiro_acessa(passageiro, &id, nome, endereco);
    if (id == 1 && strcmp(nome, "Abraão") == 0 &&
        strcmp(endereco, "Rua Taquari, 3850") == 0) {
      printf(
          "Passou no teste de acesso de passageiros\n");
      return 1;
    } else {
      printf(
          "Falhou no teste de acesso de passageiros\n");
      return 0;
    }
  } else {
    printf("Fassou no teste de acesso de passageiros\n");
    return 0;
  }
}

int teste_passageiro_libera(){

  Passageiro* passageiro = passageiro_novo(1, "Abraão", "Computação");
  Passageiro* passageiro2 = NULL;

  passageiro_libera(&passageiro);
  passageiro_libera(&passageiro2);

  if (passageiro != NULL || passageiro2 != NULL) {
    printf("Falhou no teste de liberação de passageiro.\n");
    return 0;
  } 
  
  printf("Passou no teste de liberação de passageiro.\n");
  return 1;
}

int teste_fila_cria() {
  Fila *fila = fila_cria();
  if (fila != NULL) {
    printf("Passou na função de criação de fila.\n");
    return 1;
  } else {
    printf("Falhou na função de criação de fila.\n");
    return 0;
  }
}

float teste_fila_libera_com_dados_validos() {
  float pontuacao = 0;
  Fila *fila = fila_cria();
  fila_libera(&fila);
  if (fila != NULL || fila_libera(NULL) != 0) {
    printf(
        "Falhou na função de liberar fila.\n");
    return 0;
  } else {
    printf(
        "Passou na função de criação de fila.\n");
    return 1;
  }
}

float teste_fila_busca_com_dados_validos() {
  int id;
  char nome[50];
  char endereco[100];

  Fila *fila = fila_cria();
  if (fila != NULL) {
    Passageiro *abraao = passageiro_novo(1, "Abraão", "Rua Ipanema, 221");
    fila_insere(fila, abraao);
    Passageiro *jaco = passageiro_novo(2, "Jaco", "Rua Ipanema, 222");
    fila_insere(fila, jaco);
    Passageiro *jose = passageiro_novo(3, "Jose", "Rua Ipanema, 223");
    fila_insere(fila, jose);
    Passageiro *aux = fila_busca(fila, 2);
    Passageiro *aux1 = fila_busca(NULL, 1);
    Passageiro *aux2 = fila_busca(fila, 5);
    if (aux != NULL && aux2 == NULL && aux1 == NULL) {
      passageiro_acessa(aux, &id, nome, endereco);
      if (id == 2 && strcmp(nome, "Jaco") == 0 &&
          strcmp(endereco, "Rua Ipanema, 222") == 0) {
        printf("[Passou]: Fila busca.\n");
        return 1;
      } else {
        printf("[Falhou]: Fila busca.\n");
      }
    } else {
      printf("[Falhou]: Fila busca.\n");
    }
  } else {
    printf("[Falhou]: Fila busca.\n");
  }
  return 0;
}

float teste_fila_insere() {
  Fila *fila = fila_cria();
  if (fila != NULL) {
    Passageiro *abraao = passageiro_novo(1, "Abraão", "Rua Ipanema, 221");
    Passageiro *jorge = passageiro_novo(1, "Jorge", "Rua Ipanema, 224");
    if (fila_insere(fila, abraao) == 1 && fila_insere(fila, jorge) != 0 && fila_insere(fila, NULL) == -1) {
      Passageiro *jaco = passageiro_novo(2, "Jaco", "Rua Ipanema, 222");
      if (fila_insere(fila, jaco) == 1) {
        Passageiro *jose = passageiro_novo(3, "Jose", "Rua Ipanema, 223");
        if (fila_insere(fila, jose) == 1) {
          printf("[Passou]: fila insere\n");
          return 1;
        } else {
          printf("[Falhou]: fila insere\n");
        }
      } else {
        printf("[Falhou]: fila insere\n");
      }
    } else {
      printf("[Falhou]: fila insere\n");
    }
  } else {
    printf(
        "[Falhou]: fila insere\n");
  }
  return 0;
}

int main(void) {
  printf("Hello World, Equipe\n");
  return 0;
}
