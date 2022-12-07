#include <stdio.h>
#include <string.h>


int main(){

    char str[20] = "AAbbCCDdeE";
    char str2[20] = {0};
    int i, tamanho = strlen(str)-1;
    for(i = 0; str[i] != '\0'; i++){
        str2[i] = str[tamanho - i]; 
    }
    printf("%s\n", str2);
        
    

   
    

    return 0;
}

