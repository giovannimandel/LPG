#include<stdio.h>

int main (){
    int matriz[3][3],i, j, linha;
  
    printf ("\nDigite valor para os elementos da matriz\n\n");
  
  for ( i=0; i<3; i++ )
    for ( j=0; j<3; j++ )
    {
      printf ("\nElemento[%d][%d] = ", i, j);
      scanf ("%d", &matriz[ i ][ j ]);
 }
 printf("Digite uma linha: ");
 scanf("%d", &linha);
 printf("%d\n", matriz[linha]);
    for(i = 0; i< 3; i++){
        printf(" %d ", matriz[linha][i]);
    }
}