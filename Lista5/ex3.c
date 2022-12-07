#include <stdio.h>
void calcula_circulo(float raio, float *pPerimetro, float *pArea);

int main(){

    float raio, perim, area;
    
    

    printf("valor do raio: ");
    scanf("%f", &raio);
    printf("valor do raio: %f\n", raio);

    printf("perimetro: %.2f\n", perim);
    printf("area: %.2f\n", area);

    calcula_circulo(raio, &perim, &area);

    printf("perimetro: %.2f\n", perim);
    printf("area: %.2f\n", area);


    return 0;
}

void calcula_circulo(float raio, float *pPerimetro, float *pArea){

    *pPerimetro = 2 * 3.14 * raio;
    *pArea = 3.14 * raio * raio;

}