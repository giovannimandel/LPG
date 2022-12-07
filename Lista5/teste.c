#include <stdio.h>
void conv(int x, int *pH, int *pM, int *pS);

int main(){

    int t, h, m, s;
    scanf("%d", &t);
    conv(t, &h, &m, &s);
    printf("%dh %dmin %ds\n", h, m, s);

    return 0;
}

void conv(int x, int *pH, int *pM, int *pS){
    *pH = x / 3600;// h
    int resto = x % 3600;
    *pM = resto / 60; // m
    *pS = resto % 60; //s 
}