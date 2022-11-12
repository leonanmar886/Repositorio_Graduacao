#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int teste_passageiro_novo(){
  char nome1[50] = "Carlinhos";
  char endereco1[100] = "Rua Taquari, 3850";

  char nome2[50] = "89849384"
  char endereco2[100] = "75834578"

  Passageiro* passageiro1 = passageiro_novo(1, &nome1, &endereco1);
  Passageiro* passageiro2 = passageiro_novo(-1, &nome2, &endereco2);
  Passageiro* passageiro3 = passageiro_novo(1, NULL, NULL);


}

int main(void) {
  printf("Hello World, Equipe\n");
  return 0;
}
