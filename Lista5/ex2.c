#include <stdio.h>
void troca_valor(float *x, float *y);

int main(){

    float a, b, *p1, *p2;

    p1 = &a;
    p2 = &b;

    printf("valor de a: ");
    scanf("%f", p1);

    printf("valor de b: ");
    scanf("%f", p2);

    troca_valor(p1, p2);

    printf("novo valor de a: %.2f\n", *p1);
    printf("novo valor de b: %.2f\n", *p2);


    return 0;
}

void troca_valor(float *x, float *y){
    float aux;


    aux = *x;
    *x = *y;
    *y = aux;
    
}