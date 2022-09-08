#include <stdio.h>
#include <math.h>
int primo(int n);

int main()
{   
    int a;
    printf("Digite um número: ");
    scanf("%d", &a);
    int cont = 0;
    int i = 0;
    while (cont < a){
        int bool = primo(i);
        if (bool == 1){
            printf("%d \n", i);
            cont++;
        }
        i++;
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