#include <stdio.h>
#include <string.h>
#define MAX 10
int soma_primos(int v[], int n);
int ehPrimo(int x);

int main(){
    
    int v[MAX] = {7, 3, 6, 4, 17, 157, 10, 13, 5, 15};
    printf("Soma dos numeros primos de v: %d", soma_primos(v, MAX));
                

    return 0;
}

int soma_primos(int v[], int n){
    int x=0;
    for(int i=0; i < n; i++){
        if(ehPrimo(v[i])){
            x += v[i]; 
        }
    }
    return x;    
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