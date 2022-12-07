#include <stdio.h>
#include <stdlib.h>


int *uniao( int *v1, int n1, int *v2, int n2, int *p3 );

int main(){

    int n1 = 3, n2 = 5, i;
    int v1[3] = {2, -5, 3};
    int v2[5] = {1, 0, 9, -5, 3};
    int *v3;
    int *d = uniao(v1, n1, v2, n2, v3);
    printf("vetor resultante da uniao: [");
    for (i = 0; i < 8; i++){
        printf("%d, ", d[i]);
    }
    free(d);
    return 0;
}

int *uniao( int *v1, int n1, int *v2, int n2, int *p3 ){
    p3 = malloc(sizeof(int) * (n1+n2));
    int i, j;
    for(i=0; i < n1; i++){
        p3[i] = v1[i];
    }
    for(j = 0; j < n2; j++ ){
        p3[i+j] = v2[j];
    }

    return p3;
}