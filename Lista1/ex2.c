#include <stdio.h>
#include <math.h>

void main(){

     float k, somatorio, resultado;
     int n;
     printf("Digite o valor de k:");
     scanf("%f\n", &k);

     for(n = 1; n <= k;n++){

         somatorio = somatorio + (pow(-1,(n+1)))/n;
         //resultado = 1 + somatorio;
         //printf("somatorio: %f\n", somatorio); 
     }
     
     printf("Somatorio: %f", somatorio);

    return 0;
}