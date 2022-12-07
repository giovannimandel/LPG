#include <stdio.h>
#include <stdlib.h>


int main(){

    int n;

    printf("quantidade de numeros: ");
    scanf("%d", &n);
    int v[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }

    int *vp = malloc(sizeof(int));
    int *vn = malloc(sizeof(int));

    int contp = 0, contn= 0;
    for(int i=0; i<n; i++){
        if(v[i] > 0){
            contp++;
            vp = realloc(vp, sizeof(int) * (contp+1) );
            vp[contp - 1] = v[i];
        } else if(v[i] < 0){
            contn++;
            vn = realloc(vn, sizeof(int) * (contn+1) );
            vn[contn - 1] = v[i];
        }
    }
    
    printf("vetor original: [");
    for(int i = 0; i < n; i++){
        printf("%d, ", v[i]);
    }
    printf("\nvetor positivo: [");
    for(int i = 0; i < contp; i++){
        printf("%d, ", vp[i]);
    }
    printf("\nvetor negativo: [");
    for(int i = 0; i < contn; i++){
        printf("%d, ", vn[i]);
    }


    return 0;
}