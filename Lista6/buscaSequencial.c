#include <stdio.h>
#include <stdlib.h>

int *busca(int *v, int n, int chave);

int main(){

    int v[10] = {3, 6, 7, -1, 3, 12, 9, 8, 3, 17};     
    int chave, i;

    scanf("%d", &chave);
    int *id = busca(v, 10, chave);
    if(id[0] == -1){ 
        printf("Nao encontrado\n");
    }else{
        printf("Encontrado em: \n");
        for(i = 0; id[i] != -1; i++){
            printf("%d\n", id[i]);
        }
    }
    free(id);

    return 0;
}

int *busca(int *v, int n, int chave){
    int *p = malloc(sizeof(int));
    int i, cont = 0;
    for(i = 0; i < n; i++){
        if(v[i] == chave){
            cont++;
            p = realloc(p, sizeof(int)*(cont +1));
            p[cont-1] = i;
        }
    }
    p[cont] = -1;
    return p;
}