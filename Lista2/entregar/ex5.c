#include <stdio.h>
int ehPrimo(int x);

int main(){

    int n, k;
    printf("Digite o valor de k e n: ");
    scanf("%d%d", &k, &n);
        
    do{
        k++;
        if(ehPrimo(k)){
            printf("%d eh primo\n", k);
            n--;
        }
        
    }while(n != 0);

    return 0;
}

int ehPrimo(int x){
    
    int i, cont = 0; 
    for( i = 1 ; i <= x ; i++ ){
        if( x % i == 0 ){ 
            cont++; 
        }    
    }
    if( cont == 2 ){
        return 1;
    } else
        return 0;

}