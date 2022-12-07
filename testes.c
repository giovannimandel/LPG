#include <stdio.h>
#include <math.h>

int main(){

    float somatorio, potencia;
    int n;
    //printf("valor de n:");
    //scanf("%d\n", &n);

    for(n = 1; n < 10; n++){
        
        potencia = (pow(-1,(n+1)));
        printf("potencia: %f\n", potencia);
        //somatorio = somatorio + (pow(-1,(n+1)))/n;
        //printf("somatorio: %f\n", somatorio);
    }


    return 0;
}