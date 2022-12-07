#include <stdio.h>

int main(){

    int x=1, y=2, z[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; //x recebe valor 1, y recebe valor 2, z é um vetor de tamanho 10

    int *ip, *ip2; // declarando 2 ponteiros de valor int
    printf("ip: %d, ip2 = %d\n", ip, ip2);

    ip = &x; // ip aponta para endereço de x (1)
    printf("ip: %d\n", *ip);

    y = *ip; // y recebe o valor contido no ponteiro ip (1) (y = 1)
    printf("y: %d\n", y);

    *ip = 0; // ip recebe valor 0
    printf("ip: %d\n", *ip);

    ip=&z[2]; // ip recebe endereço da posição 2 do vetor z (2)
    printf("ip: %d\n", *ip);

    ip2=&z[5]; // ip2 recebe endereço da posição 5 do vetor z (5)
    printf("ip2: %d\n", *ip2);

    int k = ip2-ip; // k = 5 - 2
    printf("k: %d\n", k);

    y = *ip+1; //y = 2 + 1 = 3
    printf("y: %d\n", y);

    (*ip)++; //2 = 1 = 3
    printf("ip: %d\n", *ip);



    return 0;
}

