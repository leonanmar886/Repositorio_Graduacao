/* Testes disponibilizados pelo João Lucas */

#include "ABB.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void testa_acessa_validos() {
  No *no = abb_cria_no(6, 'G');
  int x = abb_chave_no(no);
  char q = abb_conteudo_no(no);
  if (x == 6) {
    printf("[passou]abb_chave_no-valido\n");
  } else {
    printf("[falhou]abb_chave_no-valido\n");
  }
  if (q == 'G') {
    printf("[passou]abb_conteudo_no-valido\n");
  } else {
    printf("[falhou]abb_conteudo_no-valido\n");
  }
}

void testa_acessa_nulos() {
  No *no = NULL;
  int x = abb_chave_no(no);
  char q = abb_conteudo_no(no);
  if (x == -1) {
    printf("[passou]abb_chave_no-nulo\n");
  } else {
    printf("[falhou]abb_chave_no-nulo\n");
  }
  if (q == '#') {
    printf("[passou]abb_conteudo_no-nulo\n");
  } else {
    printf("[falhou]abb_conteudo_no-nulo\n");
  }
}

void testa_insere_validos() {
  No *no1 = abb_cria_no(5, 'E');
  No *no2 = abb_cria_no(6, 'D');
  No *no3 = abb_cria_no(3, 's');
  No *no4 = abb_cria_no(2, 'k');
  No *no5 = abb_cria_no(4, 'i');
  No *raiz = NULL;
  raiz = abb_insere_no(raiz, no1);
  raiz = abb_insere_no(raiz, no2);
  raiz = abb_insere_no(raiz, no3);
  raiz = abb_insere_no(raiz, no4);
  raiz = abb_insere_no(raiz, no5);
  if (abb_chave_no(abb_busca_no(raiz, 5)) == abb_chave_no(no1) &&
      abb_chave_no(abb_busca_no(raiz, 6)) == abb_chave_no(no2) &&
      abb_chave_no(abb_busca_no(raiz, 3)) == abb_chave_no(no3) &&
      abb_chave_no(abb_busca_no(raiz, 2)) == abb_chave_no(no4) &&
      abb_chave_no(abb_busca_no(raiz, 4)) == abb_chave_no(no5)) {
    printf("[passou]abb_insere_no-validos\n");
  } else {
    printf("[falhou]abb_insere_no-validos\n");
  }
}

void testa_insere_invalidos_nulos() {
  No *raiz = NULL;
  No *no1 = NULL;
  raiz = abb_insere_no(raiz, no1);
  if (raiz == NULL) {
    printf("[passou]abb_insere_no-invalidos\n");
  } else {
    printf("[falhou]abb_insere_no-invalidos\n");
  }
  no1 = abb_cria_no(1, 'E');
  No *no2 = abb_cria_no(1, 'F');
  raiz = abb_insere_no(raiz, no1);
  if (abb_insere_no(raiz, no2) == NULL) {
    printf("[passou]abb_insere_no-nulos\n");
  } else {
    printf("[falhou]abb_insere_no-nulos\n");
  }
}

void testa_busca_validos() {
  No *no1 = abb_cria_no(5, 'E');
  No *no2 = abb_cria_no(6, 'D');
  No *no3 = abb_cria_no(3, 's');
  No *no4 = abb_cria_no(2, 'k');
  No *no5 = abb_cria_no(4, 'i');
  No *raiz = NULL;
  raiz = abb_insere_no(raiz, no1);
  raiz = abb_insere_no(raiz, no2);
  raiz = abb_insere_no(raiz, no3);
  raiz = abb_insere_no(raiz, no4);
  raiz = abb_insere_no(raiz, no5);
  if (abb_busca_no(raiz, 4) == no5) {
    printf("[passou]abb_busca_no-validos\n");
  } else {
    printf("[falhou]abb_busca_no-validos\n");
  }
}

void testa_busca_nulos() {
  No *raiz = NULL;
  if (abb_busca_no(raiz, 1) == NULL) {
    printf("[passou]abb_busca_no-nulos\n");
  } else {
    printf("[falhou]abb_busca_no-nulos\n");
  }
}

void testa_libera_validos() {
  No *no1 = abb_cria_no(5, 'E');
  No *no2 = abb_cria_no(6, 'D');
  No *no3 = abb_cria_no(3, 's');
  No *no4 = abb_cria_no(2, 'k');
  No *no5 = abb_cria_no(4, 'i');
  No *raiz = NULL;
  raiz = abb_insere_no(raiz, no1);
  raiz = abb_insere_no(raiz, no2);
  raiz = abb_insere_no(raiz, no3);
  raiz = abb_insere_no(raiz, no4);
  raiz = abb_insere_no(raiz, no5);

  if (abb_libera_no(raiz) == 1) {
    printf("[passou]abb_libera_no-validos\n");
  } else {
    printf("[falhou]abb_libera_no-validos\n");
  }
}

void testa_libera_nulos() {
  No *no = NULL;
  if (abb_libera_no(no) == 0) {
    printf("[passou]abb_libera_no-nulos\n");
  } else {
    printf("[falhou]abb_libera_no-nulos\n");
  }
}

void testa_remove_validos() {
  No *no1 = abb_cria_no(5, 'E');
  No *no2 = abb_cria_no(6, 'D');
  No *no3 = abb_cria_no(3, 's');
  No *no4 = abb_cria_no(2, 'k');
  No *no5 = abb_cria_no(4, 'i');
  No *raiz = NULL;
  raiz = abb_insere_no(raiz, no1);
  raiz = abb_insere_no(raiz, no2);
  raiz = abb_insere_no(raiz, no3);
  raiz = abb_insere_no(raiz, no4);
  raiz = abb_insere_no(raiz, no5);
  if(abb_remove_no(raiz, 3) == no3){
    printf("[passou]abb_remove_no-validos\n");
  }else{
    printf("[falhau]abb_remove_no-validos\n");
  }
}

void testa_remove_nulos(){
  No* raiz=NULL;
  if(abb_remove_no(raiz,1)==NULL){
    printf("[passou]abb_remove_no-nulos\n");
  }else{
    printf("[falhou]abb_remove_no-nulos\n");
  }
}

void testa_altura_validos(){
  No *no1 = abb_cria_no(5, 'E');
  No *no2 = abb_cria_no(6, 'D');
  No *no3 = abb_cria_no(3, 's');
  No *no4 = abb_cria_no(2, 'k');
  No *no5 = abb_cria_no(4, 'i');
  No *raiz = NULL;
  raiz = abb_insere_no(raiz, no1);
  raiz = abb_insere_no(raiz, no2);
  raiz = abb_insere_no(raiz, no3);
  raiz = abb_insere_no(raiz, no4);
  raiz = abb_insere_no(raiz, no5);
  if(abb_altura(raiz)==2){
    printf("[passou]abb_altura-validos\n");
  }else{
    printf("[falhou]abb_altura-validos\n");
  }
}

void testa_altura_nulos(){
  No* raiz=NULL;
  if(abb_altura(raiz)==-1){
    printf("[passou]abb_altura-nulos\n");
  }else{
    printf("[falhou]abb_altura-nulos\n");
  }
}

void testa_numero_validos(){
  No *no1 = abb_cria_no(5, 'E');
  No *no2 = abb_cria_no(6, 'D');
  No *no3 = abb_cria_no(3, 's');
  No *no4 = abb_cria_no(2, 'k');
  No *no5 = abb_cria_no(4, 'i');
  No *raiz = NULL;
  raiz = abb_insere_no(raiz, no1);
  raiz = abb_insere_no(raiz, no2);
  raiz = abb_insere_no(raiz, no3);
  raiz = abb_insere_no(raiz, no4);
  raiz = abb_insere_no(raiz, no5);
  if(abb_numero(raiz)==5){
    printf("[passou]abb_numero-validos\n");
  }else{
    printf("[falhou]abb_numero-validos\n");
  }
}

void testa_numero_nulos(){
  No* raiz=NULL;
  if(abb_numero(raiz)==-1){
    printf("[passou]abb_numero-nulos\n");
  }else{
    printf("[falhou]abb_numero-nulos\n");
  }
}

void testa_pre_ordem_validos(){
  No *no1 = abb_cria_no(5, 'E');
  No *no2 = abb_cria_no(6, 'D');
  No *no3 = abb_cria_no(3, 's');
  No *no4 = abb_cria_no(2, 'k');
  No *no5 = abb_cria_no(4, 'i');
  No *raiz = NULL;
  raiz = abb_insere_no(raiz, no1);
  raiz = abb_insere_no(raiz, no2);
  raiz = abb_insere_no(raiz, no3);
  raiz = abb_insere_no(raiz, no4);
  raiz = abb_insere_no(raiz, no5);
  if(strcmp(abb_pre_ordem(raiz),"EskiD")==0){
    printf("[passou]abb_pre_ordem-validos\n");
  }else{
    printf("[falhou]abb_pre_ordem-validos\n");
  }
}

void testa_pre_ordem_nulos(){
  No* raiz=NULL;
  if(strcmp(abb_pre_ordem(raiz),"#")==0){
    printf("[passou]abb_pre_ordem-nulos\n");
  }else{
    printf("[falhou]abb_pre_ordem-nulos\n");
  }
}

void testa_ordem_validos(){
  No *no1 = abb_cria_no(5, 'E');
  No *no2 = abb_cria_no(6, 'D');
  No *no3 = abb_cria_no(3, 's');
  No *no4 = abb_cria_no(2, 'k');
  No *no5 = abb_cria_no(4, 'i');
  No *raiz = NULL;
  raiz = abb_insere_no(raiz, no1);
  raiz = abb_insere_no(raiz, no2);
  raiz = abb_insere_no(raiz, no3);
  raiz = abb_insere_no(raiz, no4);
  raiz = abb_insere_no(raiz, no5);
  if(strcmp(abb_ordem(raiz),"ksiED")==0){
    printf("[passou]abb_ordem-validos\n");
  }else{
    printf("[falhou]abb_ordem-validos\n");
  }
}

void testa_ordem_nulos(){
  No* raiz=NULL;
  if(strcmp(abb_ordem(raiz),"#")==0){
    printf("[passou]abb_ordem-nulos\n");
  }else{
    printf("[falhou]abb_ordem-nulos\n");
  }
}

void testa_pos_ordem_validos(){
  No *no1 = abb_cria_no(5, 'E');
  No *no2 = abb_cria_no(6, 'D');
  No *no3 = abb_cria_no(3, 's');
  No *no4 = abb_cria_no(2, 'k');
  No *no5 = abb_cria_no(4, 'i');
  No *raiz = NULL;
  raiz = abb_insere_no(raiz, no1);
  raiz = abb_insere_no(raiz, no2);
  raiz = abb_insere_no(raiz, no3);
  raiz = abb_insere_no(raiz, no4);
  raiz = abb_insere_no(raiz, no5);
  if(strcmp(abb_pos_ordem(raiz),"kisDE")==0){
    printf("[passou]abb_pos_ordem-validos\n");
  }else{
    printf("[falhou]abb_pos_ordem-validos\n");
  }
}

void testa_pos_ordem_nulos(){
  No* raiz=NULL;
  if(strcmp(abb_pos_ordem(raiz),"#")==0){
    printf("[passou]abb_pos_ordem-nulos\n");
  }else{
    printf("[falhou]abb_pos_ordem-nulos\n");
  }
}

int main() {
  printf("=-=-=-=-=-= Bateria de testes 1 =-=-=-=-=-=-=\n");
  testa_acessa_validos();
  printf("=-=-=-=-=-= Bateria de testes 2 =-=-=-=-=-=-=\n");
  testa_acessa_nulos();
  printf("=-=-=-=-=-= Bateria de testes 3 =-=-=-=-=-=-=\n");
  testa_insere_validos();
  printf("=-=-=-=-=-= Bateria de testes 4 =-=-=-=-=-=-=\n");
  testa_insere_invalidos_nulos();
  printf("=-=-=-=-=-= Bateria de testes 5 =-=-=-=-=-=-=\n");
  testa_busca_validos();
  printf("=-=-=-=-=-= Bateria de testes 6 =-=-=-=-=-=-=\n");
  testa_busca_nulos();
  printf("=-=-=-=-=-= Bateria de testes 7 =-=-=-=-=-=-=\n");
  testa_libera_validos();
  printf("=-=-=-=-=-= Bateria de testes 8 =-=-=-=-=-=-=\n");
  testa_libera_nulos();
  printf("=-=-=-=-=-= Bateria de testes 9 =-=-=-=-=-=-=\n");
  testa_remove_validos();
  printf("=-=-=-=-=-= Bateria de testes 10 =-=-=-=-=-=-=\n");
  testa_remove_nulos();
  printf("=-=-=-=-=-= Bateria de testes 11 =-=-=-=-=-=-=\n");
  testa_altura_validos();
  printf("=-=-=-=-=-= Bateria de testes 12 =-=-=-=-=-=-=\n");
  testa_altura_nulos();
  printf("=-=-=-=-=-= Bateria de testes 13 =-=-=-=-=-=-=\n");
  testa_numero_validos();
  printf("=-=-=-=-=-= Bateria de testes 14 =-=-=-=-=-=-=\n");
  testa_numero_nulos();
  printf("=-=-=-=-=-= Bateria de testes 15 =-=-=-=-=-=-=\n");
  testa_pre_ordem_validos();
  printf("=-=-=-=-=-= Bateria de testes 16 =-=-=-=-=-=-=\n");
  testa_pre_ordem_nulos();
  printf("=-=-=-=-=-= Bateria de testes 17 =-=-=-=-=-=-=\n");
  testa_ordem_validos();
  printf("=-=-=-=-=-= Bateria de testes 18 =-=-=-=-=-=-=\n");
  testa_ordem_nulos();
  printf("=-=-=-=-=-= Bateria de testes 19 =-=-=-=-=-=-=\n");
  testa_pos_ordem_validos();
  printf("=-=-=-=-=-= Bateria de testes 20 =-=-=-=-=-=-=\n");
  testa_pos_ordem_nulos();
  return 0;
}