#include <stdio.h>
#include <math.h>

int main(){

    float a = 2, b = 3, c = 4, somatorio, n, resultado;
    int k;
    printf("quantidade de series:\n");
    scanf("%d\n", &k);
    

    while(k != 0){

        somatorio = somatorio + (pow(-1,(n+1)))*(4/(a*b*c));
        a = a + 2;
        b = b + 2;
        c = c + 2;
        //printf("somatorio: %f\n", somatorio);
        n++;
        k--;

    }
    resultado = somatorio +3;
    printf("somatorio: %f\n", resultado);



    return 0;
}