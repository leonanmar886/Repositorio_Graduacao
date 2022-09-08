#include <stdio.h>
int primo(int n);

int main()
{   
    int a;
    printf("Digite um n�mero: ");
    scanf("%d", &a);
    
    if(a < 2){
        printf("O menor n�mero primo � 2, e %d � menor que 2, logo n�o existe um n�mero primo menor.", &a);
    } else {
        for(int i = a; i >= 2; i--){
            int bool = primo(i);
            if (bool == 1) {printf("%d \n", i);}
        }
    }
    
    return 0;
}

int primo(int n) {
    if (n == 2) {
    return 1;
    } else if (n<2 || (n%2)== 0) {
        return 0;
    } else {
        int lim = (int) sqrt(n);
        for (int i=3; i<= lim; i+=2) {
            if (n% i == 0) {
                return 0;
            }
        }
        return 1;
    }
}
