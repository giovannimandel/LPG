#include <stdio.h>
#include <locale.h>
#include <windows.h>
#define M 8
#define N 10
int busca_seq(int v[], int n, int chave);
void uniao(int a[], int b[], int c[]);
void intersecao(int a[], int b[], int c[]);
int conta_valores(int v[]);
void mostra_vetor(int v[], int n);

int main(){

    int matriz[M][N] = {0}, i, j, valor, cont = 0, linha, a, x=0, linha1, linha2, valorBusca, tam;
    setlocale(LC_ALL, "portuguese");

    do{
        // printf("\n");
        // for(i=0; i<M; i++){
        //     for(j=0; j<N; j++){
        //         printf("%4d ", matriz[i][j]);
        //     }
        //     printf("\n");
        // }       

        printf("\n");
        printf("1- Criar um novo conjunto vazio\n");
        printf("2- Inserir dados em um conjunto\n");
        printf("3- Remover um conjunto\n");
        printf("4- Fazer a união entre dois conjuntos\n");
        printf("5- Fazer a interseção entre dois conjuntos\n");
        printf("6- Mostrar um conjunto\n");
        printf("7- Mostrar todos os conjuntos\n");
        printf("8- Busca por um valor\n");
        printf("9- Sair do programa\n");
        scanf("%d", &valor);
        if(valor < 1 || valor > 9){
            printf("Valor fora do escopo!\n");
        }
        
        switch (valor){
            case 1:
                //Criar novo conjunto vazio
                if(cont >= M){
                    printf("A matriz atingiu seu tamanho máximo!\n");
                    break;
                }
                printf("Conjunto %d Criado!\n", cont);
                cont++;
                break;
            case 2:
                //Inserir dados em um conjunto
                if(cont <= 0){ 
                    printf("Não há cojuntos existentes\n");
                    break;
                } 
                printf("Qual conjunto?\n");
                scanf("%d", &linha);
                printf("\n");
                if(linha > cont-1 && linha <= M){
                    printf("Conjunto %d ainda não criado!\n", linha);
                    break;
                }else if(linha < 0 || linha > M){
                    printf("Conjunto inválido!\n");
                    break;
                }else if(conta_valores(matriz[linha]) != 0){
                    tam = conta_valores(matriz[linha]);
                    x=0;
                    for ( j = tam; j < N; j++){
                        scanf("%d", &matriz[linha][j]);
                        if(matriz[linha][j] == 0){
                            break;
                        }
                        if(busca_seq(matriz[linha], x, matriz[linha][j]) == 1){
                            printf("Já existe esse valor! Insira outro\n");
                            j--;
                            continue;  
                        }
                        x++;
                        
                    }
                    printf("Valores inseridos com sucesso!\n");
                } else{
                    x=0;
                    for ( j = 0; j < N; j++){
                        scanf("%d", &matriz[linha][j]);
                        if(matriz[linha][j] == 0){
                            break;
                        }
                        if(busca_seq(matriz[linha], x, matriz[linha][j]) == 1){
                            printf("Já existe esse valor! Insira outro\n");
                            j--;
                            continue;  
                        }
                        x++;
                        
                    }
                    printf("Valores inseridos com sucesso!\n");
                }
                break;
            case 3:
                //Remover um conjunto
                if(cont <= 0){
                    printf("Não existem conjuntos para remover!\n");
                    break;
                }
                printf("Qual conjunto deseja remover?\n");
                scanf("%d", &linha);
                if((0<=linha)&&(linha<cont)){
					cont--;
					do{
						linha++;
						for(i = 0; i<N; i++){
							matriz[linha-1][i] = matriz[linha][i];
						}
                        for(i=0; i<N; i++){
                            matriz[linha][i] = 0;
                        }
					}while(linha<cont);
				}else{
					printf("Conjunto Inválido");
				}
                break;
            case 4:
                //Uniao entre dois conjuntos
                if(cont <=1){
                    printf("Existe apenas um conjunto!\n");
                    break;
                }
                if(cont >= M){
                    printf("Sem espaço para mais conjuntos\n");
                    break;
                } else{
                    cont++;
                    printf("Digite os conjuntos que deseja fazer a união: ");
                    scanf("%d", &linha1);
                    scanf("%d", &linha2);
                    if(conta_valores(matriz[linha1]) + conta_valores(matriz[linha2]) > N){
                        printf("A união desses conjuntos ultrapassa o tamanho permitido\n");
                        break;
                    }
                    uniao(matriz[linha1], matriz[linha2], matriz[cont-1]);
                }    
                break;    
            case 5:
                //Interseção de conjuntos
                if(cont <=1){
                    printf("Existe apenas um conjunto!\n");
                    break;
                }
                if(cont >= M){
                    printf("Sem espaço para mais conjuntos\n");
                    break;
                } else{
                    cont++;
                    printf("Digite os conjuntos que deseja fazer a interseção: ");
                    scanf("%d", &linha1);
                    scanf("%d", &linha2);
                    intersecao(matriz[linha1], matriz[linha2], matriz[cont-1]);
                } 
                break;
            case 6:
                //Mostrar um conjunto
                if(cont < 1){
                    printf("Não existem conjuntos para a serem mostrados!\n");
                    break;
                }
                printf("Qual o conjunto que deseja mostrar?\n");
                scanf("%d", &linha);
                if(linha > cont-1 && linha <= M){
                    printf("Conjunto %d ainda não criado!\n", linha);
                    break;
                }else if(linha < 0 || linha > M){
                    printf("Conjunto inválido!\n");
                    break;
                }
                printf("\n");
                if(matriz[linha][0] == 0){
                    printf("Conjunto %d = vazio\n", linha);
                    break;
                } else{
                    printf("Conjunto %d = ", linha);
                    mostra_vetor(matriz[linha], conta_valores(matriz[linha]));
                    break;
                }               
                break;
            case 7:
                //Mostrar todos os conjuntos
                if(cont < 1){
                    printf("Não existem conjuntos para a serem mostrados!\n");
                    break;
                }
                printf("Há %d conjuntos:\n", cont);
                for(i = 0; i < cont; i++){
                    if(matriz[i][0] == 0){
                        printf("%d = vazio\n", i);
                    } else{
                        printf("%d = ", i);
                        mostra_vetor(matriz[i], conta_valores(matriz[i]));
        
                    }
                }
                break;
            case 8:
                //Busca por um valor
                if(cont < 1){
                    printf("Não existem conjuntos para buscar um valor!\n");
                    break;
                }
                printf("Qual o valor a ser buscado?\n");
                scanf("%d", &valorBusca);
                printf("O valor forncecido ocorre nos conjuntos: ");    
                for(i = 0; i < cont; i++){
                    for(j = 0; j < N; j++){
                        if(valorBusca == matriz[i][j]){
                            printf("%d ", i);
                        }
                    }
                }
                printf("\n");
                break;            
            default:
                break;
        }
    }while(valor != 9);

    return 0;
}

int busca_seq(int v[], int n, int chave){
    int i;
    for(i=0; i < n; i++){ 
        if(v[i] == chave){ 
            return 1;
        }    
    }
    return -1;
}

void uniao(int a[], int b[], int c[]){
    int i, j;
    for(i =0; a[i]!=0; i++){
        c[i] = a[i];
    }
    int n = conta_valores(b);
    for(j = 0; b[j]!= 0; j++){
        if(busca_seq(a, n, b[j])==-1){
            c[i]=b[j];
            i++;
        }
    }
    while(i<N){
        c[i] = 0;
        i++;
    }
}
void intersecao(int a[], int b[], int c[]){
    int i, j, k=0;
    for(i = 0; a[i]!=0; i++){
        for(j = 0; b[j]!=0; j++){
            if(a[i] == b[j]){
                c[k] = b[j];
                k++;
            }
        }   
    }
    while(i<N){
        c[i] = 0;
        i++;
    }
}

int conta_valores(int v[]){
     int i;
     for( i = 0; v[i] != 0; i++){
        if(i == N){
            return i;
        }
     }
     return i;
     
 }

void mostra_vetor(int v[], int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}
