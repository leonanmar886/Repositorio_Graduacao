#include <stdio.h>
#include <math.h>

void PreencherVetor(int* v, int n);
void PerguntaAdiciona(int* v);
int* Adicionar(int* v);
void ExibeVetor(int* v);

int main(void) {
    int n;
    printf("Qual o tamanho do seu vetor ?");
    scanf("%d", &n);

    int *v = (int*) malloc(n * sizeof(int));

    PreencherVetor(v, n);

    PerguntaAdiciona(v);
    return 0;
}

void PreencherVetor(int* v, int n){
    printf("Insira %d valores inteiros. \n", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
}

void PerguntaAdiciona(int* v){
    char resposta;
    int* nv;
    printf("Você deseja inserir mais elementos ? ");
    scanf("%c", &resposta);
    if (resposta == 'nao'){
        return 0;
        ExibeVetor(v);
        free(v);
    } else if (resposta == 'sim') {
        nv = Adicionar(v);
        PerguntaAdiciona(nv);
    } else{
        printf("Resposta inválida.");
        return 0;
    }
}

int* Adicionar(int* v) {
    int n;
    int* nv;
    printf("Quantas posicoes voce deseja adicionar ? ");
    scanf("%d", &n);

    nv = realloc(v, n * sizeof(int));
    return nv;
}

void ExibeVetor(int* v) {
    int tamanho = sizeof(v) / sizeof(int);
    for(int i = 0; i < tamanho; i++) {
        printf("%d", v[i]);
    }
}
