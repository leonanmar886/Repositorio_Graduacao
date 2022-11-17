#include "TravelBooking.h"

typedef struct voo Voo;


// verifica se algum dos valores na struct voo é nulo. Se sim, retorna -1. Se não, retorna 1
int voo_verifica(Voo *voo);

// acessa o voo e copia as informações dele para as variáveis passadas como parâmetro
void voo_acessa(Voo *voo, int *codigo, char *origem, char *destino);

// atribui NULL ao voo
void libera_voo(Voo **voo

// edita os campos do voo
void edita_voo(Voo *voo, int codigo, char *origem, char *destino)