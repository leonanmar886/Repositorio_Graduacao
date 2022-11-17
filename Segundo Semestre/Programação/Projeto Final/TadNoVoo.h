typedef struct no_voo No_Voo;
typedef struct lista_voo Lista;

// cria uma lista encadeada de voos
Lista *cria_lista();

// libera uma lista existente e retorna 1 se foi possível e -1 se não foi possível
int libera_lista(Lista **lista);