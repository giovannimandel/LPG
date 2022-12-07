#include <stdio.h>
#include <stdlib.h>
int *diagonal_secundaria( int **matriz, int ordem );

int main(){

    int **p;
    int lin, col, i, j;

    printf("Digite quantas linhas e colunas:\n");
    scanf("%d%d", &lin, &col);

    p = malloc(sizeof(int) * lin);

    for(i=0; i<lin; i++){
        p[i] = malloc(sizeof(int) * col);
    }


    for(i = 0; i < lin; i++){
        for(j = 0; j < col; j++){
            scanf("&d", &p[i][j]);
        }
    }



    
}

int *diagonal_secundaria( int **matriz, int ordem ){
    

}
