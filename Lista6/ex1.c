#include <stdio.h>
#include <stdlib.h>

float *clone(float *v, int n);

int main(){

    float v[5] = {0, 1, 2, 3, 4};
    float *p;
    p = clone(v, 5);
    for(int i = 0; i < 5; i++){
        printf("%.2f - ", p[i]);
    }
    free(p);


    return 0;
}



float *clone(float *v, int n){
    float *p;
    p = malloc(sizeof(int) * n);
    for(int i=0; i < n; i++){
        p[i] = v[i];
    }
    return p;
}