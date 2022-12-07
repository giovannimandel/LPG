#include <stdio.h>
#include <string.h>
char trim(char str[]);

int main(){

    char str[] = "     Alo mundo!  ";

   trim(str);

    return 0;
}

char trim(char str[]){
    int k=0, i;
    while(str[k] == ' '){
        k++;
    }
    for(i=0; i <= strlen(str)-k; i++){
        str[i] = str[i+k];
    }

    for(k=0; str[k]!=0; k++);
    k--;
    while(k == ' '){
        k--;
    }
    
    str[k+1] = 0;

}
