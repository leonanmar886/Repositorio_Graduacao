#include <stdio.h>
#include "geofig.h"
#include <stdlib.h>
#include <math.h>

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

void pto_atribui(struct Ponto *p, float x, float y){
  (*p).x = x;
  (*p).y = y;
}

float pto_distancia(struct Ponto* p1, struct Ponto* p2){
  float coordenadaX1, coordenadaX2, coordenadaY1, coordenadaY2, distancia;
  coordenadaX1 = (*p1).x;
  coordenadaX2 = (*p2).x;
  coordenadaY1 = (*p1).y;
  coordenadaY2 = (*p2).y;

  distancia = sqrt(pow(coordenadaX2 - coordenadaX1, 2) + pow(coordenadaY2 - coordenadaY1, 2)); // a distancia entre dois ponto x e y é raiz de (xB – xA)² + (yB – yA)².

  return distancia;

}