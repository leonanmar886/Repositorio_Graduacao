#include "TadVoo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct voo {
  int codigo;
  char *origem[100];
  char *destino[150];
};

// voo verifica
// voo novo 
// voo libera
// voo acessa (leitura)
// voo edita

int voo_verifica(Voo *voo) {
  int codigo_aux;
  char origem_aux[100];
  char destino_aux[150];
  
  voo_acessa(voo, codigo_aux, origem_aux, destino_aux);
  if (codigo_aux < 0 || origem_aux == NULL || destino_aux == NULL) {
    return -1;
  }
  else {
    return 1;
  }
}
  
  
void voo_acessa(Voo *voo, int *codigo, char *origem, char *destino) {
  if(voo == NULL){
    *codigo = -1;
    strcpy(origem, "NULL");
    strcpy(destino, "NULL");  
  }
  else {
    *codigo = voo->codigo;
    strcpy(origem, voo->origem);
    strcpy(destino, voo->destino);
  }
}


void libera_voo(Voo **voo) {
  if(voo != NULL){
    free(*voo);
    *voo = NULL;      
  } 
}


void edita_voo(Voo *voo, int codigo, char *origem, char *destino) {
  if (voo != NULL && verifica(codigo, origem, destino) == 1) {
    voo->codigo = codigo;
    strcpy(voo->origem, origem);
    strcpy(voo->destino, destino);
  }  
}


