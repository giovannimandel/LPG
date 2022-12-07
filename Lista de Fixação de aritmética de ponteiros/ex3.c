#include <stdio.h>

int main() { 
    int v[10] = {7, 13, 8, 1, 9, 4, 27, 17, 6, 2};
    int *pv; 
    int i; 
    pv = v;  
    for(i=0;i<10;i++) {       
        printf("\n%i - %i - %i - %i",v[i],&v[i],(pv+i),*(pv+i));
        printf("\n%i - %i - %i - %i",&pv[i],pv[i],*(v+i),(v+i)); 
        } 
    return 0;    
}