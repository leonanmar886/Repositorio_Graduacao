#include <stdio.h>
#include <math.h>

int main(void) {
    //Primeira Questao
    /*double raio;
    printf("Digite o raio da esfera: \n");
    scanf("%lf", &raio);
    double volume = 4/(3*pow(raio,3));
    printf("O volume da esfera e: %4.2lf\n", volume);*/ 

    //Segunda Questao
    const double capacidadeGalao = 3.7854;
    double valorUSA, taxaConversao, valorLitrosUSA, valorLitroBR;
    printf("Digite o preco do galao de gasolina nos EUA: \n");
    scanf("%lf", &valorUSA);
    printf("Digite o a taxa de conversao do dolar para o real: \n");
    scanf("%lf", &taxaConversao);
    valorLitrosUSA = valorUSA/capacidadeGalao;
    valorLitroBR = valorLitrosUSA/taxaConversao;
    printf("O valor do litro em reais e: %3.2lf\n", valorLitroBR);
return 0;
}