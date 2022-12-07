#include <stdio.h>
void inverte_string(char str[]);

int main(){

    return 0;
}

void inverte_string(char str[]){
    char str2[20] = {0};
    int i, tamanho = strlen(str)-1;
    for(i = 0; str[i] != '\0'; i++){
        str2[i] = str[tamanho - i]; 
    }
    
}    