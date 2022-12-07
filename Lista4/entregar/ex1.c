#include <stdio.h>
int contem(char s[], char c);

int main(){

    char c, s[10] = "Abacate";
    printf("Digite uma letra: ");
    scanf("%c", &c);
    if(contem(s, c)) printf("%s contem %c", s, c);
    else printf("%s nao contem %c", s, c);

    return 0;
}

int contem(char s[], char c){
    for(int i=0; s[i]!='\0'; i++){
        if(s[i] == c){
            return 1;
        } 
    }
    return 0;
}