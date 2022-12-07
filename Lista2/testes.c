#include <stdio.h>

int somaDigitoImpar(int x, int y);

int main(){

    int x, y;
    printf("Digite dois inteiros: ");
    scanf("%d%d", &x, &y);
    somaDigitoImpar(x, y);
    // switch(somaDigitoImpar(x, y)){
    //     case 0:
    //         printf("soma: %d", somaDigitoImpar(x, y));
    //         break;
    //     case 1:
    //         printf("soma: %d", somaDigitoImpar(x, y));
    //         break;
    //     case 2:
    //         printf("soma: %d", somaDigitoImpar(x, y));
    //         break;
    //     case 3:
    //         printf("soma: %d", somaDigitoImpar(x, y));
    //         break;
    // }    


    return 0;
}

int somaDigitoImpar(int x, int y){
    int soma=0;

    if(x > y){
        if((y % 2) == 0 ){
            for(int i=y+1; i<x; i+=2){
                soma +=i;
            }
            return printf("soma: %d", soma);
        }else {
            for(int i=y; i<x; i+=2){
                soma += i;
            }
            return printf("soma: %d", soma-y);    
        }
    }else {
        if((x % 2) == 0){
            for(int i=x+1; i<y; i+=2){
                soma += i;              
            }
            return printf("soma: %d", soma);
        } else{
            for(int i=x; i<y; i+=2){
                soma += i;
            }
            return printf("soma: %d", soma-x);
        }
    }
}           
