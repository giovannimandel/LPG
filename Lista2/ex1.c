#include <stdio.h>
int tipo_triangulo(float x, float y, float z);

int main(){

    float x, y, z;
    printf("Digite os tres lados de um triangulo: ");
    scanf("%f%f%f", &x, &y, &z);
    switch(tipo_triangulo(x, y, z)){
        case 0:
            printf("Os lados nao formam um triangulo");
            break;
        case 1:
            printf("Os lados formam um triangulo equilatero");
            break;
        case 2:
            printf("Os lados formam um triangulo isosceles");
            break;
        case 3:
            printf("Os lados formam um triangulo escaleno");            
    }

    return 0;
}

int tipo_triangulo(float x, float y, float z){
    if(x + y <= z || x + z <= y || y + z <= x){
        return 0;
    } else if(x == y && x == z && y == z){
        return 1;
    } else if((x == y) != z || (x == z) != y || (y == z) != x){
        return 2;
    } else if(x != y && x != z && y != z){
        return 3;
    }    

}