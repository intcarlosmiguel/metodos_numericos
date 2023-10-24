#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
typedef double (*Funcao)(double);

double Func(double x) {
    return -0.5*x*x + 2.5*x+4.5;
}

double F2(double x) {
    return 5*x*x*x - 5*x*x +6*x - 2;
}

double F3(double x){
    return -25 + 82*x - 90*pow(x,2) +44*pow(x,3) - 8*pow(x,4) + 0.7*pow(x,5);
}

void find_raiz(int metodo,Funcao F,double a,double b){
    switch (metodo){
        case 1: // Método da bisceção
            if(F(a)*F(b) > 0) printf("Não existe mínimo nesse intervalo!");
            else{
                double erro = 100;
                double x = a;
                double* anterior = calloc(2,sizeof(double));
                anterior[0] = F(a);
                anterior[1] = F(b);
                double x_ = 0;
                while (anterior[0]*anterior[1] < 0){
                    
                    x = (a+b)/2;
                    if(F(x)*anterior[0] < 0){
                        anterior[1] = F(x);
                        erro = fabs((x - x_)/x);
                        b = x;
                        
                    }
                    if(F(x)*anterior[1] < 0){
                        anterior[0] = F(x);
                        erro = fabs((x - x_)/x);
                        a = x;
                        
                    }
                    
                    printf("%f %f \n",x,erro);
                    if(F(x) == 0) break;
                    if(erro < 0.001) break;
                    x_ = x;
                }
                
                printf("\nRaiz = %f\n",x);
                free(anterior);
            }
            break;
        case 2:
            if(F(a)*F(b) > 0) printf("Não existe mínimo nesse intervalo!");
            else{
                double erro = 100;
                double x = a;
                double* anterior = calloc(2,sizeof(double));
                anterior[0] = F(a);
                anterior[1] = F(b);
                double x_ = 0;
                while (anterior[0]*anterior[1] < 0){
                    
                    x = b - (anterior[1])*(a - b)/(anterior[0] - anterior[1]);
                    if(F(x)*anterior[0] < 0){
                        anterior[1] = F(x);
                        erro = fabs((x - x_)/x);
                        b = x;
                        
                    }
                    if(F(x)*anterior[1] < 0){
                        anterior[0] = F(x);
                        erro = fabs((x - x_)/x);
                        a = x;
                        
                    }
                    
                    printf("%f %f %f\n",x,erro,F(x));
                    if(F(x) == 0) break;
                    if(erro < 0.001) break;
                    x_ = x;
                }
                printf("\nRaiz = %f\n",x);
                free(anterior);
            }
            break;
        default:
            printf("Método não encontrado\n");
            break;
    }
}


int main(){
    // Primeira questão
    find_raiz(1,Func,2.5,10);
    find_raiz(1,F2,0,1);
    find_raiz(1,F3,0.5,1);
    find_raiz(2,F3,0.5,1);
    return 0;
}
