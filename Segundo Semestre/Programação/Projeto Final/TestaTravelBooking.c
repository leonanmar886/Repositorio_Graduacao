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
    printf("Falho no teste de criação de passageiro.");
    return 0;
  }

  printf("Passou no teste de criação de passageiro.");
  return 1;
}

int main(void) {
  printf("Hello World, Equipe\n");
  return 0;
}
