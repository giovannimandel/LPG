#include <stdio.h>
int fatorial(int x);

void main(){
    int n;
    printf("Digite um numero: ");
    

//nao peguei na aula

}

int fatorial(int x){
    if(x == 0){
        printf("[Caso base: retorna 1]\n");
        return 1;
    } else{
        printf("[Caso recursivo: x=%d --> %d*%d!...\n", x, x, x-1);
        int y = fatorial(x-1); //chamada recursiva
        printf("[Retorno da recursao: %d! = %d]\n", x-1, y);
        return x*y;
    }
}