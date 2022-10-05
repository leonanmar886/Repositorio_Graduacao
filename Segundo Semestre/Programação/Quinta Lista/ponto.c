#include <stdio.h>
#include "geofig.h"
#include <stdlib.h>

struct Ponto {
    float x, y;
};

Ponto* pto_cria(float x, float y){
  struct Ponto *p = (struct Ponto*) malloc(sizeof(struct Ponto));
  return p;
}

void pto_libera(Ponto *p){
  void free(p);
}

void pro_acessa(struct Ponto *p, float* cordenadax, float* cordenaday){
    cordenadax = (float*) malloc(sizeof(float));
    cordenaday = (float*) malloc(sizeof(float));
    *cordenadax = p->x;
    *cordenaday = p->y;
}