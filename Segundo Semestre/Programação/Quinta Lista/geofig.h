/* TAD: Ponto (x,y) */
/* Tipo exportado */
typedef struct ponto Ponto;
/* Funções exportadas */
/* Aloca e retorna um ponto com coordenadas (x,y) */
Ponto* pto_cria(float x, float y);
/* Libera a memória de um ponto previamente criado */
void pto_libera(Ponto* p);
/* Copia valores os das coordenadas de um ponto para x e y*/
void pto_acessa(Ponto *p, float* cordenadax, float* cordenaday);
/* Atribui novos valores às coordenadas de um ponto */
void pto_atribui(struct Ponto *p, float x, float y);
/* Retorna a distância entre dois pontos */
float pto_distancia(struct Ponto* p1, struct Ponto* p2);

/* TAD: Circulo (ponto,raio) */
/* Tipo exportado */
typedef struct circulo Circulo;
/* Funções exportadas */
/* Aloca e retorna um circulo com base no ponto e no raio informados */
Circulo* circ_cria(Ponto* p, float raio);
/* Libera a memória de um circulo previamente criado */
void circ_libera(Circulo* c);
/* Copia os valores das coordenadas de um circulo e seu raio para x, y e r */
void circ_acessa(Circulo* c, float* x, float* y, float* r);
/* Atribui novos valores às coordenadas de um ponto e seu raio */
void circ_atribui(Circulo* c, float x, float y, float r);
/* Retorna 1 se o ponto pertence ao circulo ou 0, caso contrário */
int circ_pertence(Circulo* c, Ponto* p);
/* Retorna o cálculo da área do circulo */
float circ_area(Circulo* c);

/* TAD: Triangulo (ponto,ponto,ponto) */
/* Tipo exportado */
typedef struct triangulo Triangulo;
/* Funções exportadas */
/* Aloca e retorna um triangulo com base nos pontos */
Triangulo* tria_cria(Ponto* p1, Ponto* p2, Ponto* p3);
/* Libera a memória de um triangulo previamente criado */
void tria_libera(Triangulo* t);
/* Copia os valores dos pontos de um triângulo em p1, p2 e p3*/
void tria_acessa(Triangulo* t, Ponto* p1, Ponto* p2, Ponto* p3);
/* Atribui novos valores aos pontos de um triângulo */
void tria_atribui(Triangulo* t, Ponto* p1, Ponto* p2, Ponto* p3);
/* Retorna 1 se os pontos do triângulo atendem a condição de existência e 0, caso
contrário */
int tria_verifica(Triangulo* t);
/* Retorna 1 se o ponto pertence ao triângulo ou 0, caso contrário */
int tria_pertence (Triangulo* t, Ponto* p);
/* Retorna o cálculo da área do triângulo */
float tria_area(Triangulo* t);

/* TAD: Quatrilatero (ponto,ponto,ponto,ponto) */
/* Tipo exportado */
typedef struct quatrilatero Quatrilatero;
/* Funções exportadas */
/* Aloca e retorna um quatrilatero com base nos pontos */
Quatrilatero* quad_cria(Ponto* p1, Ponto* p2, Ponto* p3, Ponto* p4);
/* Libera a memória de um quatrilatero previamente criado */
void quad_libera(Quatrilatero* q);
/* Copia os valores dos pontos de um quatrilatero para p1, p2, p3 e p4 */
void quad_acessa(Quatrilatero* q, Ponto* p1, Ponto* p2, Ponto* p3, Ponto* p4);
/* Atribui novos valores aos pontos de um quatrilatero */
void quad_atribui(Quatrilatero* q, Ponto* p1, Ponto* p2, Ponto* p3, Ponto* p4);
/* Retorna 1 se o ponto pertence ao quatrilatero ou 0, caso contrário */
int quad_pertence(Quatrilatero* q, Ponto* p);
/* Retorna o cálculo da área do quatrilatero */
float quad_area(Quatrilatero* q);