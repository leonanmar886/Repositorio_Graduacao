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

    //Quarta Questao
    /*int quantia;
    int qtdCem = 0;
    int qtdVint = 0;
    int qtdCinc = 0;
    int qtdDois = 0;
    int qtdUm = 0;
    int qtdDez = 0;
    int qtdCinq = 0;
    printf("Digite o valor: \n");
    scanf("%d", &quantia);

    if (quantia > 100){
        qtdCem = 0;
        while (quantia >= 100) {
            quantia -= 100;
            qtdCem++;
        }
    }
    if (quantia >= 50){
        qtdCinq = 0;
        while (quantia >= 50) {
            quantia -= 50;
            qtdCinq++;
        }
    }
    if (quantia >= 20){
        qtdVint = 0;
        while (quantia >= 20) {
            quantia -= 20;
            qtdVint++;
        }
    }
    if (quantia >= 10){
        qtdDez = 0;
        while (quantia >= 10) {
            quantia -= 10;
            qtdDez++;
        }
    }
    if (quantia >= 5){
        qtdCinc = 0;
        while (quantia >= 5) {
            quantia -= 5;
            qtdCinc++;
        }
    }
    if (quantia >= 2){
        qtdDois = 0;
        while (quantia >= 2) {
            quantia -= 2;
            qtdDois++;
        }
    }
    if (quantia >= 1){
        qtdUm = 0;
        while (quantia >= 1) {
            quantia -= 1;
            qtdUm++;
        }
    }
    printf("%d notas de 100, %d notas de 50, %d notas de 20, %d notas de 10, %d notas de 5, %d notas de 2 e %d notas de 1.", qtdCem, qtdCinq, qtdVint, qtdDez, qtdCinc, qtdDois, qtdUm);
    */
    //Quinta Questao
    /* int n1,n2, n3, auxVariable, biggerN;
    printf("Digite um número: ");
    scanf("%d", &n1);
    printf("Digite um número: ");
    scanf("%d", &n2);
    printf("Digite um número: ");
    scanf("%d", &n3);
    if(n1 > n2 && n1 > n3) {
        biggerN = n1;
        if (n2 >= n3) { 
            auxVariable = n1;
            n1 = n3;
            n3 = auxVariable;
        } else {
            auxVariable = n2;
            n2 = n3;
            n3 = auxVariable; 
            auxVariable = n1;
            n1 = n3;
            n3 = auxVariable;           
        }
    } else if (n3 > n1 && n3 > n2) {
        biggerN = n3;
        if (n1 >= n2) {
            auxVariable = n1;
            n1 = n2;
            n2 = auxVariable;
        }
    } else if (n2 > n1 && n2 > n3) {
        biggerN = n2;
        if (n1 >= n3) {
            auxVariable = n1;
            n1 = n3;
            n3 = auxVariable;
            auxVariable = n2;
            n2 = n3;
            n3 = auxVariable;
        } else {
            auxVariable = n2;
            n2 = n3;
            n3 = auxVariable;           
        }
    }
    printf("A ordem crescente é: %d, %d, %d e o maior número é: %d", n1,n2,n3, biggerN);
    */
return 0;
}