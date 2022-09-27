#include <stdio.h>
#include <math.h>

double calcularDelta(double a, double b, double c);
int raizes(double a, double b, double c, double delta, double *r1, double *r2);

int main(){
    int a, b, c;
    double delta, raiz1, raiz2;
    printf("Insira o valor do coeficiente a: ");
    scanf("%d", &a);
    printf("Insira o valor do coeficiente b: ");
    scanf("%d", &b);
    printf("Insira o valor do coeficiente c: ");
    scanf("%d", &c);
    if(a == 0){
        printf("O coeficiente a deve ser diferente de 0");
        return 0;
    }
    delta = calcularDelta(a, b, c);
    raizes(a, b, c, delta, &raiz1, &raiz2);
    printf("A raiz 1 é %f e a raiz 2 é %f.", raiz1, raiz2);
    return 0;
}

int raizes(double a, double b, double c, double delta, double *r1, double *r2){
    if(delta == 0){
        double raiz = -b * (2*a);
        *r1 = raiz;
        *r2 = raiz;
    } else if(delta > 0) {
        double raiz1 = (-b - sqrt(delta))*(2 * a);
        double raiz2 = (-b + sqrt(delta))*(2 * a);
        *r1 = raiz1;
        *r2 = raiz2;
    } else {
        printf("A expressão não possui raiz real.");
    }
    return 0;
}

double calcularDelta(double a, double b, double c){
    double deltaFuncao = pow(b, 2) - 4 * a * c;
    return deltaFuncao;
}