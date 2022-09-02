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
    /*const double capacidadeGalao = 3.7854;
    double valorUSA, taxaConversao, valorLitrosUSA, valorLitroBR;
    printf("Digite o preco do galao de gasolina nos EUA: \n");
    scanf("%lf", &valorUSA);
    printf("Digite o a taxa de conversao do dolar para o real: \n");
    scanf("%lf", &taxaConversao);
    valorLitrosUSA = valorUSA/capacidadeGalao;
    valorLitroBR = valorLitrosUSA/taxaConversao;
    printf("O valor do litro em reais e: %3.2lf\n", valorLitroBR);*/

    //Terceira Questao
    /*float tempoSegundos, segundos;
    int horas, minutos;
    printf("Digite o tempo em segundos: \n");
    scanf("%lf", &tempoSegundos);
    segundos = (int)tempoSegundos % 60; //os segundos serão o resto da divisão para transformar em minutos.
    minutos = (int)tempoSegundos/60 % 60; // os minutos serão o resultado da divisão dos segundos por 60, transformando assim o tempo total em minutos, e depois o resto da divisão desse valor por 60.
    horas = tempoSegundos / 3600; // as horas serão simplesmente o valor da divisão do tempo total em segundos por 3600.
    printf("O período decorrido foi de %2.1d horas, %2.1d minutos e %5.2f segundos\n", horas, minutos, segundos);*/

return 0;
}