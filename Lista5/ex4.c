#include <stdio.h>
void calcula_hora(int totalMinutos, int *ph, int *pm);

int main(){

    int total, hora, min;

    printf("tempo em minutos: ");
    scanf("%d", &total);

    calcula_hora(total, &hora, &min);
    printf("tempo -> %dh %dm", hora, min);

    return 0;
}

void calcula_hora(int totalMinutos, int *ph, int *pm){

    *ph = totalMinutos / 60;
    int resto = totalMinutos - (*ph * 60);
    *pm = resto; 

}