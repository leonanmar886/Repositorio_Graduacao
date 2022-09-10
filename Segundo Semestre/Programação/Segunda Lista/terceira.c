#include <stdio.h>
#include <math.h>
int MDC(int a, int b);
int MDCDif(int a, int b, int c);

int main()
{   
    int a, b, c;
    printf("Digite um numero: ");
    scanf("%d", &a);
    printf("Digite um numero: ");
    scanf("%d", &b);
    printf("Digite um numero: ");
    scanf("%d", &c);

    printf("%d", MDCDif(a, b, c));
    
    return 0;
}

int MDCDif(int a, int b, int c){
    if (c == 0){
        return MDC(a, b);
    } else {
        return MDC(MDC(a,b), c);
    }
}

int MDC(int a, int b) {
    if(b == 0){
        return a;
    } else {
        return MDC(b, a%b);
    }
}