#include <stdio.h>
int ehPrimo(int x);
int checkPrime(int number);

int main(){

    int k;
    printf("Digite o valor de k: ");
    scanf("%d", &k);
    if(ehPrimo(k)) printf("%d eh primo", k);
    else printf("%d nao eh primo");
        
    

    return 0;
}

int checkPrime(int number)
{
  int count = 0;
  for(int i=2; i<=number/2; i++){
     if(number%i == 0){
       count=1;
       break;
     }
  }
  if(number == 1) count = 1;
  return count;
}

int ehPrimo(int x){
    
    int i, cont = 0;
    for( i = 1 ; i <= x ; i++ ){
        if( x % i == 0 ){ 
            cont++; 
        }    
    }
    if( cont == 2 ){
        return 1;
    } else
        return 0;
           

}