#include <stdio.h>
void max_min(int vet[], int tam, int *pMin, int *pMax);

int main(){

    int v[5] = {5, 12, 0, 23, 8};
    int tam = 5, min, max;

    max_min(v, tam, &min, &max);
    printf("Min: %d\nMax: %d\n", min, max);

    return 0;
}

void max_min(int vet[], int tam, int *pMin, int *pMax){
    *pMin = vet[0];
    *pMax = vet[0];
    int i;

    for(i = 0; i < tam; i++){
        if(vet[i] > *pMax){
            *pMax = vet[i];
        } else if(vet[i] < *pMin){
            *pMin = vet[i];
        }
    }
}