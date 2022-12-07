#include <stdio.h>
void uniao(int a[],int b[],int c[]);
int conta_valores(int v[]);
int busca_seq(int v[], int n, int chave);

int main(){

    int matriz[3][3],i, j, linha1, linha2;
  
    printf ("\nDigite valor para os elementos da matriz\n\n");
  
    for ( i=0; i<3; i++ )
        for ( j=0; j<3; j++ )
        {
        printf ("\nElemento[%d][%d] = ", i, j);
        scanf ("%d", &matriz[ i ][ j ]);
    }
    printf("Digite os indices dos conjuntos: ");
    scanf("%d", &linha1);
    for(i = 0; i<3; i++){
        v1[i] = matriz[linha][i];
    }
    scanf("%d", &linha2);
    for(i = 0; i < 3; i++){
        v2[i] = matriz[linha][i];
    }
    
    uniao(v1, v2, matriz[]);

}

void uniao(int a[], int b[], int c[]){
    int i, j;
    for(i =0; a[i]!=0; i++){
        c[i] = a[i];
    }
    int n = conta_valores(b);
    for(j = 0; b[j]!= 0; j++){
        if(busca_seq(a, n, b[j])==-1){
            c[i]=b[j];
            i++;
        }
    }
    while(i<N){
        c[i] = 0
        i++;
    }
}

 int conta_valores(int v[]){
     int i;
     for( i = 0; v[i] != 0; i++);
     return i;
 }

 int busca_seq(int v[], int n, int chave){
    int i;
    for(i=0; i < n; i++){ 
        if(v[i] == chave) return i;
    }
    return -1;
}