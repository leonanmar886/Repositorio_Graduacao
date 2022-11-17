#include "TravelBooking.h"


typedef struct passageiro Passageiro;

//   Aloca e retorn um passageiro com os dados passados por parâmetro
Passageiro* passageiro_novo(int id, char* nome, char* endereço);

void passa_libera(Passageiro** passageiro);

void leitura_passageiro(Passageiro* passa, int* id, char* nome, char* endereco);

void passageiro_edita(Passageiro* passa, int id, char* nome, char* end);
  
  

  