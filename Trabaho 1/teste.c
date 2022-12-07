#include <stdio.h>
int busca_seq(int v[], int n, int chave);
void mostra_vetor(int v[], int n);
static int BuscaSequencial(int v[], int tl, int valor);

int main(){

    int matriz[3][3],i, j, linha, v[6];
  
    printf ("\nDigite valor para os elementos da matriz\n\n");
  
    for ( i=0; i<3; i++ ){
        for ( j=0; j<3; j++ ){
            printf ("\nElemento[%d][%d] = ", i, j);
            scanf ("%d", &matriz[ i ][ j ]);
        }
    }    
    printf("Digite uma linha: ");
    scanf("%d", &linha);
    for(i = 0; i< 3; i++){
        printf(" %d ", matriz[linha][i]);
        v[i] = matriz[linha][i];
    }

    int x, tl=6;
    scanf("%d", &x);
    while(x!=0){
        while(busca_seq(v, i, x) != -1){
        printf("%d repetido!\n", x);
        scanf("%d", &x);
    }
         v[i] = x;
         i++;
    }

    mostra_vetor(v, i);

    return 0;
}

int busca_seq(int v[], int n, int chave){
    int i;
    for(i=1; i <= n; i++){ 
        if(v[i] == chave){ 
            return 1;
        }    
    }
    return -1;
}

void mostra_vetor(int v[], int n){
    for(int i = 0; i < n; i++){
        printf("%d:%d\n", i, v[i]);
    }
}

int BuscaSequencial(int v[], int tl, int valor){
    int i = 0;
    while (i < tl && v[i] != valor){
        i++;
    }
    if (i >= tl){
        i = -1;
    }
    return i;
}