#include <stdio.h>

void main(){

    float n, k, resultado, somatorio;
    printf("Digite o valor de k: %f\n", k);
    scanf("%f", &k);
    
    

    for(n = 1;n <= k;n++){

        somatorio = somatorio + (1/n);
        //resultado = somatorio;
    }
    printf("Somatorio: %f", somatorio);


    return 0;
}