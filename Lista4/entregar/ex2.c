#include <stdio.h>
int contem(char s[], char c);

int main(){

    char c, s[10] = "Banana";
    printf("Digite uma letra: ");
    scanf("%c", &c);
    if(contem(s, c)) printf("%s contem %c, com %d ocorrencias", s, c, contem(s,c));
    else printf("%s nao contem %c", s, c);

    return 0;
}

int contem(char s[], char c){
    int cont=0;
    for(int i=0; s[i]!='\0'; i++){
        if(s[i] == c || s[i] == c-32){            
            cont++;
        } 
    }
    if(cont != 0) return cont;
    else return 0;
}