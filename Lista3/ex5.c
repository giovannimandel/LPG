#include <stdio.h>
#define MAX 10
int busca_seq_rec(int v[], int n, int chave);

int main(){

    int v[MAX] = {6, 9, 4, -3, 17, 22, 13, 81, 44, 32};
    int chave, n, a; 
    printf("Digite a chave: ");
    scanf("%d", &chave);
    a = busca_seq_rec(v, MAX, chave);
    if(a == -1) printf("Nao encontrado\n");
    else printf("Encontrado em %d\n", a);

    return 0;
}
 
int busca_seq_rec(int v[], int n, int chave){
   if(v[n] == chave) return n;
   else busca_seq_rec(v, n-1, chave);
   
   if(n == -1) return -1;
}

