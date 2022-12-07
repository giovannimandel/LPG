#include <stdio.h>

int main(){ 
    int x[5] = {9, 11, 22, 33, 44}; //vetor v de variável double
    int *px; // ponteiro do tipo double
    int i; // variavel do i tipo int
    px = x; // ponteiro px aponta para vetor x -----> CORREÇÃO: aponta para primeiro elemento do vetor x
    printf("\n\n teste : %d\n", *px);
    for(i=0;i<7;i++) {       
        printf("\n%d",*px); // printa o endereço de px  ------> CORREÇÃO: printa os elementos de x usando o ponteiro px
        px++;
        
    }
   
    // printf("\n\n%d\n", *px);
    // px = px + 1;
    // printf("%d\n", *px);
    // px= px + 2;
    // printf("%d\n", *px);

    px = x;  // px aponta pra primeiro elemento do vetor x
    // printf("%d\n", *px);
    // px++;
    // printf("%d\n", *px);
    // px = x;
    // printf("%d\n", *px);
    for(i=0;i<5;i++) {       
        printf("\n%d",*(px+i)); // printa os valores do vetor x usando o ponteiro px;
    }
    printf("\n%d", *px);
    return 0;
}       