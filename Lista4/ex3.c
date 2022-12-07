#include <stdio.h>
void concatena (char str1[], char str2[]);

int main(){

    char str1[10] = "Alo";
    char str2[10] = "Mundo";
    concatena(str1, str2);

    return 0;
}

void concatena (char str1[], char str2[]){
    int cont=0;
    for(int n=0; str1[n] != '\0'; n++){
        cont++;
    }
    for(int i=0; str2[i]!= '\0'; i++){
        str1[cont++] = str2[i];
    }
    printf("%s", str1);
}