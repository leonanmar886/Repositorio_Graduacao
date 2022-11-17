#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Passageiro.h"

int teste_passageiro_novo(){
  char nome1[50] = "Carlinho";
  char endereco1[100] = "Rua Taquari, 3850";

  char nome2[50] = "89849384";
  char endereco2[100] = "75834578";

  Passageiro* passageiro1 = passageiro_novo(1, nome1, endereco1); // passageiro com dados válidos.
  Passageiro* passageiro2 = passageiro_novo(-1, nome2, endereco2); // passageiro com dados inválidos.
  Passageiro* passageiro3 = passageiro_novo(1, NULL, NULL); // passageiro com dados nulos,

  if(passageiro1 == NULL || passageiro2 != NULL || passageiro3 != NULL){
    printf("Falho no teste de criação de passageiro.\n");
    return 0;
  }

  printf("Passou no teste de criação de passageiro.\n");
  return 1;
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

int main(void) {
  printf("Hello World, Equipe\n");
  return 0;
}

int testa_voo_novo(){
  int codigo_valido = 550;
  char origem_valido[100] = "Londres";
  char destino_valido[100] = "Sobral";

  int codigo_invalido = -2;
  char origem_invalido[100] = NULL;
  char destino_invalido =  NULL;

  Voo* Voo_Valido = voo_novo(codigo_valido, origem_valido, destino_valido);
  Voo* Voo_Igual = voo_novo(codigo_valido, origem_valido, origem_valido);
  Voo* Voo_Invalido = voo_novo(codigo_invalido, origem_valido, destino_invalido);
  Voo* Voo_Nulo = voo_novo(NULL, origem_invalido, origem_invalido);

  if (Voo_Valido == NULL || Voo_Igual != NULL || Voo_Invalido != NULL || Voo_Nulo != NULL){
    printf("Voo_Cria: [FALHOU]");
    return 0;
  }
  else if(Voo_Valido != NULL && Voo_Igual == NULL || Voo_Invalido == NULL || Voo_Nulo == NULL){
    printf("Voo_Cria: [PASSOU]");
    return 1;
  }
  else{
    printf("Voo_Cria: [ERRO]");
    return -1;
  }
}

int testa_voo_libera(){
  int codigo_valido = 550;
  char origem_valido[100] = "Londres";
  char destino_valido[100] = "Sobral";

  int codigo_invalido = -2;
  char origem_invalido[100] = NULL;
  char destino_invalido =  NULL;

  Voo* Voo_Valido = voo_novo(codigo_valido, origem_valido, destino_valido);
  Voo* Voo_Nulo = NULL;
  int aux_1 = voo_libera(Voo_Valido);
  int aux_2 = voo_libera(Voo_Nulo);
    if (aux_1 != 1 || aux_2 != 0 || Voo_Valido != NULL || Voo_Nulo != NULL){
    printf("Voo_Libera: [FALHOU]");
    return 0;
  }
  else if (aux_1 == 1 && aux_2 == 0 && Voo_Valido == NULL && Voo_Nulo == NULL){
    printf("Voo_Libera: [PASSOU]")
    return 1;
  }
  else{
    printf("Voo_Libera[FALHOU]");
    return -1
  }


