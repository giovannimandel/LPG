#include <stdio.h>
int ehDigito(char x);

int main(){

    char x;
    printf("Digite um caracter: ");
    scanf("%c", &x);
    ehDigito(x);

    return 0;
}

int ehDigito(char x){
    if(x >= 48 && x <= 57){
        int a = (int)x-48;
        return printf("O caracter representa o digito %d", a);
        
    } else{
        return printf("Nao representa um digito entre 0 e 9");
    }
}