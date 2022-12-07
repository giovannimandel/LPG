#include <stdio.h>
void inc_dec(int *a, int *b);

int main(){

    int a, b, *p1, *p2;
    
    p1 = &a;
    p2 = &b;

    printf("valor de a: ");
    scanf("%d", p1);

    printf("valor de b: ");
    scanf("%d", p2);

    inc_dec(p1, p2);

    printf("novo valor de a: %d\n", *p1);
    printf("novo valor de b: %d\n", *p2);


    return 0;
}

void inc_dec(int *a, int *b){
    (*a)++;
    (*b)--;
}