#include "TadNoVoo.h"
#include "TadVoo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct no_voo {
  Voo *voo;
  struct no_voo *proximo;
};

struct lista_voo { 
  struct no_voo *primeiro;
};

Lista* cria_lista() {
  Lista *nova_lista = (Lista *) malloc(sizeof(Lista));
  nova_lista->primeiro = NULL;
  return nova_lista;
}

int libera_lista(Lista **lista) {
  if (lista != NULL) {
    free(*lista);
    *lista = NULL;
    return 1;
  }
  return -1;
}

Lista* buscar_lista(Lista *lista, int codigo) {
  
}