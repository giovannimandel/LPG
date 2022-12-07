#include <stdio.h>
void fibonacci(int v[], int n);

int main(){
    
    int n, v[50];
    printf("Digite a quantidade de termos: ");
    scanf("%d", &n);
    fibonacci(v, n-1);

    return 0;
}

void fibonacci(int v[], int n){
    int a=0, b=1, c=0;
    for(int i=0; i<n; i++){
        c = a + b;
        a = b;
        b = c;
        v[i] = c;
    }
    printf("Vetor: [1, ");
    for(int j=0; j<n; j++){
             
        if(j == (n-1)){
             printf("%d]", v[j]);
        } else{
             printf("%d, ", v[j]);
        }
    }
}