#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *repetidor( char *s, int n );

int main(){

    char s[3];
    scanf("%s", &s);
    char *d = repetidor(s, 3);
    printf("%s", d);

}

char *repetidor( char *s, int n ){
    char *p = malloc(sizeof(int) * n);
    int i, j;
    for(i = 0; i < n; i++){
        strcat(p, s);
    }

    return p;
}