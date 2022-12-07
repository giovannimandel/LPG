#include <stdio.h>
void inc(int *x);


int main(){
    // int v[5] = {2, 4, 6, 8, 10};
    // printf("Endereco de V: %d\n", v );
    // int i;
    // for( i = 0; i < 5 ; i++ ){
    //     printf("V[%d] ", i);
    //     printf("(%d) ", &v[i]);
    //     printf("= %d\n", v[i]);
    // }


    // int v[5];
    // int *p = v; // &v ou &v[0]
    // int i;
    // for( i = 0; i < 5 ; i++ ){
    //     scanf("%d", &p[i] );
    // }
    // for( i = 0; i < 5 ; i++ ){
    //     printf("%d\n", v[i] ); // Acessa v diretamente.
    // }


    // int v[4] = { 1, 4, 7, 11 };
    // int *i; // ponteiro
    // for( i = v; i < v + 4 ; i++ ){
    //     printf("V[%d] ", i - v );
    //     printf("(%d) ", i );
    //     printf("= %d\n", *i );
    // }

    // int n = 5, *p;
    // p = &n;
    // printf("%d", p);
    // printf("%d", *p);

    // int v[5] = {2, 4, 6, 8, 10};
    // printf("Endereco de V: %d\n", v );


    int n = 1;
    inc(&n);
    printf("%d", n);

    return 0;
}

void inc(int *x){
    x[0]++;
}