#include <stdio.h>
void max_vetor(float vet[], int tam, float *pMax, int *pIndice);

int main(){

    float v[5] = {5, 12, 0, 23, 8}, max;
    int tam = 5, indice; 

    max_vetor(v, tam, &max, &indice);
    printf("Max: %.2f, com indice %d\n", max, indice);

    return 0;
}

void max_vetor(float vet[], int tam, float *pMax, int *pIndice){
    *pMax = vet[0];
    int i;

    for(i = 0; i < tam; i++){
        if(vet[i] > *pMax){
            *pMax = vet[i];
            *pIndice = i;
        }
    }
}