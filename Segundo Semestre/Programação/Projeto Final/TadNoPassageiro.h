typedef struct passageiro Passageiro;
typedef struct lista_passageiro Lista;
typedef struct  no_passageiro No;

Lista* cria_lista();

int libera_lista(Lista **lista);

Passageiro* buscar_lista(Lista* lista, int id);

int inserir_lista(Lista* lista, Passageiro* passa);

Passageiro* remover_lista(Lista* lista);

