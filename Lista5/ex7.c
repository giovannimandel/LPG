#include <stdio.h>
void min_matriz(float mat[3][4], float *pMin, int *pI, int *pJ);

int main(){

    float mat[3][4] = { 5, 12, 0, 23, 
                        8, 13, 65, 41, 
                        14, 23, 42, 98
                      };
    int tam = 5, lin, col;
    float min; 

    min_matriz(mat, &min, &lin, &col);
    printf("Min: %.2f, na linha %d e coluna %d\n", min, lin, col);

    return 0;
}

void min_matriz(float mat[3][4], float *pMin, int *pI, int *pJ){
    *pMin= mat[0][0];
    int i, j;

    for(i = 0; i < 3; i++){
        for(j = 0; j < 4; j++){
            if(mat[i][j] < *pMin){
            *pMin = mat[i][j];
            *pI = i+1;
            *pJ = j+1;
        }
        }
        
    }
}