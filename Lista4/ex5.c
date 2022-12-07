#include <stdio.h>

int main(){


    return 0;
}

void minusc_maiusc(char str[]){
    for(int i=0; str[i] != '\0'; i++){
        if(str[i] >= 97 && str[i] <= 122){
            str[i] = str[i]-32;
        }
    }

}