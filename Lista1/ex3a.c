#include <stdio.h>
#include <math.h>

void main(){

    float k, somatorio = 0, n = 1, a = 1;
    printf("Digite o valor de k:");
    scanf("%f", &k);
    

    while(k != 0){
        
        printf("valor de n: %f\n", n);
        printf("valor de k: %f\n", k);
        printf("valor de a: %f\n", a);
        somatorio = somatorio + (pow(-1,(a+1)))*(4/n);
        printf("Somatorio: %f\n", somatorio);
        
        n=n+2;
        k--;
        a++;
    }
   



   
    

    return 0;
}