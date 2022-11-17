#include "TadNoPassageiro.h"
#include "Tadpassageiro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




struct no_passageiro {
  Passageiro *passageiro;
  struct no_passageiro *proximo;
};

struct lista_passageiro {
  struct no_passageiro *primeiro;
};

Lista* cria_lista(){
  Lista* nova_lista = (Lista *)malloc(sizeof(Lista));
   nova_lista->primeiro = NULL;
  return nova_lista;
  
}

int libera_lista(Lista **lista){
  if(lista != NULL){
    if((*lista)->primeiro != NULL){
      No* aux = (*lista)->primeiro;
      do{
        passa_libera(&aux->passageiro);
        aux = aux->proximo;
      } while(aux != NULL);
    }
    free(*lista);
    *lista = NULL;
    return 1;
  }
  return 0;
}

Passageiro* buscar_lista(Lista* lista, int id){
  if (lista==NULL && lista->primeiro==NULL){
  return NULL;
}
  
 No* x = lista->primeiro;
  
  int id_aux;
  char nome[100];
  char end[150];
leitura_passageiro((x->passageiro),&id_aux,nome,end);
 
  while(x!=NULL ) {

    if(id == id_aux){
      return x->passageiro;
    }
    x =  x->proximo;
    
    }

  
  return NULL;

}

int inserir_lista(Lista* lista, Passageiro* passa){
  if(lista == NULL || passa == NULL){
    return -1;
  }
  if(lista->primeiro!= NULL){
    int id;
    char nome[100];
    char end[150];
    leitura_passageiro(passa, &id, nome, end);
    Passageiro *aux =buscar_lista(lista, id);
    if(aux != NULL){
      return 0;
    }
    
  }
  if (lista->primeiro == NULL){
    No* novo =(No *) malloc(sizeof(No));
    novo->passageiro = passa;
    novo->proximo = NULL;
    lista->primeiro = novo;
  }
  else {
    No* ultimo = lista->primeiro;
    while( ultimo->proximo != NULL){
      ultimo = ultimo->proximo;
    }
  No* novo = (No *)malloc(sizeof(No));
  novo->passageiro = passa;
  novo->proximo = NULL;
  ultimo->proximo = novo;  
    
  }
  return 1;
  
}

Passageiro* remover_lista(Lista* lista){
  if(lista == NULL ||lista->primeiro == NULL){
    return NULL;
  }
  Passageiro* viajante = lista->primeiro->passageiro;
  lista->primeiro = lista->primeiro->proximo;
  return viajante;
}



