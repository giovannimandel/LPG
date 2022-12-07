#include <stdio.h>
#define MAX 5 
float compara(float a[], float b[], float n);

float main(){

    float a[MAX] = {2.0, 6.0, 9.0, 8.0, 4.0};
    float b[MAX] = {2.0, 6.0, 9.0, 8.0, 4.0};
    if(compara(a, b, MAX)){
        printf("Os vetores sao iguais");
    } else{
        printf("Os vetores sao diferentes"); 
    }
    return 0;
}

float compara(float a[], float b[], float n){
    
    for(int i=0; i < n; i++){
        printf("valores %.3f e %.3f\n", a[i], b[i]);
        if(a[i] != b[i]){
            return 0;
        }
    }
    return 1;
}        
