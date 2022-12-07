#include <stdio.h>
#define MAX 10
void busca_todos(int v[], int n, int chave, int indices[]);

int main(){

    int n=10, chave=0;
    int v[MAX]= {3, 6, 7, -1, 3, 12, 9, 8, 3, 17};
    int indices[MAX] = {};
    printf("Digite a chave: ");
    scanf("%d", &chave);
    busca_todos(v, MAX, chave, indices);
    int i;
    printf("Indices = {");
    for(int i=0; i<n; i++){
        if(i == n-1){
            printf("%d}", indices[i]);
        } else{
            printf("%d, ", indices[i]);
        } 
    }

    return 0;
}

void busca_todos(int v[], int n, int chave, int indices[]){
    
    int j=0;
    for(int i=0; i<n; i++){
        if(v[i] == chave){
            indices[j] = i;
            j++;
        }
    }
    for(int i=j; i<n; i++){
        indices[i] = -1;
    }
}