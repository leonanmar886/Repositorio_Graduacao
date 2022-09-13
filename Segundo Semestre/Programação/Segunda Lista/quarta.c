#include <stdio.h>
#define Pi 3.14

int main(){
    int raio;
    printf("Qual o raio da esfera ? ");
    scanf("%d", &raio);
    printf("O volume da esfera de raio %d e %d, enquanto a area e %d.", raio, volume(raio), area(raio));
    return 0;
}

int area(int raio){
    int areaEsfera = 4 * Pi * (raio * raio);
    return areaEsfera;
}

int volume(int raio){
    int volumeEsfera = (4/3) * Pi * (raio * raio * raio);
    return volumeEsfera;
}