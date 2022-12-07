#include <stdio.h>
int eh_numero(char s[]);
int eh_digito(char c);

int main(){

    char s1[20] = {0};
    scanf("%s", &s1);
    if(eh_numero(s1)) printf("'%s' soh tem digito", s1);
    else printf("'%s' nao tem soh digitos", s1);

    return 0;
}

int eh_numero(char s[]){
    int i;
    for(i=0; s[i] != 0; i++){
        if(!eh_digito(s[i])) return 0;
    }
    return 1;
}

int eh_digito(char c){
    return c >= '0' && c <= '9';
}