#include <stdio.h>
#include <string.h>
#include <math.h>

int str_em_int(char s[]);

int str_em_int(char s[]);
        
int main(){

    char s[20] = "12454534";
    printf("Resultado: %d", str_em_int(s));

    return 0;
}

int str_em_int(char s[]){
    int a=0;
    for(int i=strlen(s)-1; i >= 0; i--){
        a += (s[i]-48) * pow(10,(strlen(s) - (i+1)));
    }
    return a;

}
