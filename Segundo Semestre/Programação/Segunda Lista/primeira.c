#include <stdio.h>
int MDC(int a, int b);

int main(){
    int a, b;
    printf("Digite um número: ");
    scanf("%d", &a);
    printf("Digite um número: ");
    scanf("%d", &b);
    printf("%d", MDC(a, b));
    return 0;
}

int MDC(int a, int b){
    int r;
    while(b != 0){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}