#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
typedef double (*Funcao)(double);

double Func(double x) {
    return exp(-x)-x;
}
double dev1(double x) {
    return -exp(-x)-1;
}

void ponto_fixo(Funcao F,double inicio){
    double erro = 10;
    double proximo;
    while (erro > 0.001){
        proximo = F(inicio) + inicio;
        erro = fabs((proximo - inicio)/proximo);
        inicio = proximo;
        printf("Erro: %f\n", erro);
    }
    printf("\nRaiz = %f\n\n",inicio);
}

void Newton_Raphson(Funcao F,Funcao derivada,double inicio){
    double erro = 10;
    double proximo;
    while (erro > 0.001){
        proximo =inicio -  F(inicio)/derivada(inicio);
        erro = fabs((proximo - inicio)/proximo);
        inicio = proximo;
        printf("Erro: %f\n", erro);
    }
    printf("\nRaiz = %f\n\n",inicio);
}

void secante(Funcao F,double inicio,double proximo){
    double erro = 10;
    double i;
    while (erro > 0.001){
        i =proximo -  F(proximo)*(inicio - proximo)/(F(inicio) - F(proximo));
        erro = fabs((i - proximo)/i);
        inicio = proximo;
        proximo = i;
        printf("Erro: %f\n", erro);
    }
    printf("\nRaiz = %f\n\n",inicio);
}


int main(){
    // Primeira questão
    ponto_fixo(Func,0);
    Newton_Raphson(Func,dev1,0);
    secante(Func, 0,1);
    return 0;
}