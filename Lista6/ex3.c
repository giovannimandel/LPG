#include <stdio.h>
#include <stdlib.h>

int main(){
    float v[5] = {1, 2, 3, 4, 5}, tam = 5;
    float media;
    for(int i = 0; i < tam; i++){
        media += v[i]; 
    }
    media = media/tam;
    printf("media: %f\n", media);

    printf("numeros maiores ou iguais que a media:\n");

    float *p = malloc(sizeof(int));
    int cont=0;
    for(int i=0; i < tam; i++){
        if(v[i] >= media){
            cont++;
            p = realloc(p, sizeof(int) * (cont+1));
            p[cont-1] = v[i]; 
        }
    }
    for(int i=0; i < cont; i++){
        printf("%.2f\n", *(p+i));
    }

}

