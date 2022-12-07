#include <stdio.h>
int fibo(int n);

int main(){

    int n, i;
    printf("Digite a quantidade de termos: ");
    scanf("%i", &n);
    int a = 1, b = 1;
    if(n<=2){
        printf("%d\n%d\n", a, b);
    } else{
        printf("%d\n%d\n", a, b);
        do{
            printf("%d\n",fibo(n));
            n--;
        }while (n != 0);
    }

    return 0;
}

int fibo(int n){
    int a = 1, b = 1, atual, i;
    int f[n+1];
    for( i = 3 ; i <= n ; i++ ){
        atual = a + b; 
        printf("%i: %i\n", i, atual);
        a = b; 
        b = atual;
         atual; 
    }


}