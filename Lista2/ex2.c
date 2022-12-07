#include <stdio.h>
int maiorValor(int x, int y, int z);

int main(){

    int x, y, z;
    printf("Digite tres valores inteiros: ");
    scanf("%d%d%d", &x, &y, &z);
    maiorValor(x, y, z);

    return 0;
}

int maiorValor(int x, int y, int z){
    if(x >= y && x >= z){
        return printf("%d eh o maior valor", x);
    }else if(y >= z && y >= x){
        return printf("%d eh o maior maior valor", y);
    }else if(z >= x && z >= y){
        return printf("%d eh o maior valor", z);
    }

}