#include <stdio.h>
#include <string.h>
int eh_palindromo(char str[]);

int main(){


    char str[20] = "arthur";
    if(eh_palindromo(str)) printf("%s eh palindromo", str);
    else printf("%s nao eh palindromo", str);

    return 0;
}

int eh_palindromo(char str[]){
    char str2[20] = {0};
    int i, tamanho = strlen(str)-1;
    for(i = 0; str[i] != '\0'; i++){
        str2[i] = str[tamanho - i]; 
    }
    if(strcmp(str2, str) == 0){
       return 1;

   } else{
       return 0;
   }
}