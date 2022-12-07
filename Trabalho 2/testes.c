#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

struct data{
    int dia;
    int mes;
    int ano;
};

struct horario{
    int hora;
    int minuto;
};

struct evento{
    struct data dataEvento;
    struct horario horarioInicio;
    struct horario horarioFim;
    char descricao[20];
    char local[20];
};

int insereEvento(struct evento *evento);
void insereData(struct data *data);
int checaData(struct data data);
int checaHora(struct horario inicio, struct horario fim);
int verificaConsistencia(struct evento *v, int n, struct evento e);
void ordenaDataSelectionSort(struct evento *evento, int n);
void mostraEventos(struct evento evento);
int comparaData(struct data dataEvento, struct data dataBuscada);
int joga_pro_final(struct evento *evento, int n, int a, int m, int d, int h);
int comparadorDeHora(struct horario x, struct horario y);
int deuConflito(struct evento x, struct evento y);

//setlocale(LC_ALL,"Portuguese");

int main(){
    

    int opcao, totalEventos = 0, contador = 0, h;
    struct evento *eventos = NULL;
    struct data dataBuscada, dataBuscada2;
    struct evento eventoA;

    FILE *f;

    f = fopen("cadastro.txt", "rt");
    if(f != NULL){
        
        fscanf(f, "%d", &totalEventos);
        eventos = malloc(sizeof(struct evento) * totalEventos);

        for(int i = 0; i<totalEventos; i++){
            fscanf(f, "%i", &eventos[i].dataEvento.dia);
			fscanf(f, "%i", &eventos[i].dataEvento.mes);
			fscanf(f, "%i", &eventos[i].dataEvento.ano);
			fscanf(f, "%i", &eventos[i].horarioInicio.hora);
			fscanf(f, "%i", &eventos[i].horarioInicio.minuto);
			fscanf(f, "%i", &eventos[i].horarioFim.hora);
			fscanf(f, "%i", &eventos[i].horarioFim.minuto);
			fscanf(f, " %[^\n]", eventos[i].descricao);
			fscanf(f, " %[^\n]", eventos[i].local);
        }
        fclose(f);
        printf("%d registros carregados com sucesso!\n", totalEventos);
    }

    do{
        printf("\n----------Agenda de Eventos----------\n");
        printf("1- Cadastrar\n");
        printf("2- Mostrar todos os eventos da agenda\n");
        printf("3- Mostrar todos os eventos de uma data\n");
        printf("4- Mostrar todos os eventos que tenham descricaoo\n");
        printf("5- Remover evento\n");
        printf("6- Sair\n");

        scanf("%d", &opcao);

        switch (opcao){
            case 1:
                printf("Inserir evento\n");

                if(insereEvento(&eventoA)){
                    if(verificaConsistencia(eventos, totalEventos, eventoA)){
                        totalEventos++;
                        eventos = realloc(eventos, sizeof(struct evento)*totalEventos);
                        eventos[totalEventos-1] = eventoA;
                    }else{
                        printf("Conflito existente no evento\n");
                    }
                }else{
                    printf("Falha ao adicionar evento (Data ou hora invalidas)\n");
                }

                if(totalEventos > 0){
                    ordenaDataSelectionSort(eventos, totalEventos);
                }
                break;
            case 2:
                if(totalEventos > 0){
                    for(int i = 0; i<totalEventos; i++){
                        printf("Evento %d\n", i+1);
                        mostraEventos(eventos[i]);
                    }
                } else{
                    printf("Não há eventos\n");
                }
                break;
            case 3:
                if(totalEventos>0){
                    printf("Insira a data que deseja buscar:\n");
                    insereData(&dataBuscada);

                    for(int i=0; i>totalEventos; i++){
                        if(comparaData(eventos[i].dataEvento, dataBuscada)){
                            printf("Evento encontrado:\n Evento %d", i+1);
                            mostraEventos(eventos[i]);
                            contador++;
                        }
                    }
                    if(contador == 0){
                        printf("Não há eventos nessa data\n");
                    }
                    contador = 0;
                }else{
                    printf("Não há eventos\n");
                }
                break;
            case 4:
                if(totalEventos>0){
                    char descricaoBuscada[20];
                    printf("Insira a descricao do evento buscado\n");
                    scanf(" %[^\n]", descricaoBuscada);
                    
                    contador = 0;
                    for(int i = 0; i<totalEventos; i++){
                        if(strcmp(eventos[i].descricao, descricaoBuscada) == 0){
                            printf("Evento encontrado:\n");
                            mostraEventos(eventos[i]);
                            contador++;
                        }
                    }
                    if(contador == 0){
                        printf("Nao ha eventos com essa descricao\n");
                    }
                }else{
                    printf("Não há eventos\n");
                }
                break;
            case 5:
                if(totalEventos > 0){
                    insereData(&dataBuscada2);
                    printf("Digite a hora: ");
                    scanf("%d", &h);

                    if(joga_pro_final(eventos, totalEventos, dataBuscada2.ano, dataBuscada2.mes, dataBuscada2.dia, h)){
                        totalEventos--;
                        eventos = realloc(eventos, sizeof(struct evento) * totalEventos);
                        ordenaDataSelectionSort(eventos, totalEventos);
                    }
                    ordenaDataSelectionSort(eventos, totalEventos);
                }else{
                    printf("Não há eventos\n");
                }
                break;
            default:
                break;                        
        }

    }while(opcao!=6);

    f = fopen("cadastro.txt", "wt");
    for(int i = 0; i<totalEventos; i++){
        fprintf(f, "%d\n%d\n%d\n", eventos[i].dataEvento.dia, eventos[i].dataEvento.mes, eventos[i].dataEvento.ano);
        fprintf(f, "%d\n%d\n", eventos[i].horarioInicio.hora, eventos[i].horarioInicio.minuto);
        fprintf(f, "%d\n%d\n", eventos[i].horarioFim.hora, eventos[i].horarioFim.minuto);
        fprintf(f, "%s\n%s\n", eventos[i].descricao, eventos[i].local);
    }

    fclose(f);
    free(eventos);
    
    return 0;

    return 0;
}


int insereEvento(struct evento *evento){
    insereData(&evento->dataEvento);
    if(checaData(evento->dataEvento)!=1){
        return 0;
    }


    printf("\nHora de inicio: ");
    scanf("%2d", &evento->horarioInicio.hora);
    printf("\nMinuto de inicio: ");
    scanf("%2d", &evento->horarioInicio.minuto);
    printf("\n\nHora de fim: ");
    scanf("%2d", &evento->horarioFim.hora);
    printf("\nMinuto de fim: ");
    scanf("%2d", &evento->horarioFim.minuto);
    printf("\n");

    if(checaHora(evento->horarioInicio, evento->horarioFim) != 1){
        return 0;
    }

    printf("\nDescricao do evento:\n");
    scanf(" %[^\n]", evento->descricao);
    printf("\nLocal:\n");
    scanf(" %[^\n]", evento->local);

    return 1;
}


void insereData(struct data *data){
    printf("\nDia:");
    scanf("%d", &data->dia);
    printf("\nMes:");
    scanf("%d", &data->mes);
    printf("\nAno:");
    scanf("%d", &data->ano);
}

int checaData(struct data data){
    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);

    printf("Data atual: %2d/%2d/%4d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

    if(data.ano < tm.tm_year + 1900){
        printf("\nImpossivel adicionar eventos para anos passados.\n");
        return 0;
    } else if(data.ano == tm.tm_year + 1900 && data.mes < tm.tm_mon +1 ){
        printf("Impossivel adicionar para meses passados nesse ano.\n");
        return 0;
    } else if(data.ano == tm.tm_year + 1900 && data.mes == tm.tm_mon + 1 && data.dia < tm.tm_mday){
        printf("Esse dia ja passou\n");
        return 0;
    } else if(data.mes > 12 || data.mes < 1){
        printf("Mes invalido\n");
        return 0;
    } else if(data.dia > 30 || data.dia < 1){
        printf("Dia invalido\n");
        return 0;
    }

    return 1;
}

int checaHora(struct horario inicio, struct horario fim){
    if(inicio.hora > fim.hora){
        printf("Evento nao pode iniciar depois de seu fim\n");
        return 0;
    } else if(inicio.hora == fim.hora){
        if(inicio.minuto > fim.minuto){
            printf("Evento nao pode iniciar depois de seu fim\n");
            return 0;
        }
    }else if(inicio.hora < 0 || inicio.hora > 23){
        printf("Erro em 'hora inicio'\n");
        return 0;
    }else if(fim.hora < 0 || fim.hora > 24){
        printf("Erro em 'hora fim'");
        return 0;
    }
     else if(inicio.minuto < 0 || inicio.minuto > 59){
        printf("Erro em 'minuto inicio'\n");
        return 0;
    } else if(fim.minuto < 0 || fim.minuto > 59){
        printf("Erro em 'minuto fim'\n");
        return 0;
    }

    return 1;
}

int verificaConsistencia(struct evento *v, int n, struct evento e){
    for(int i = 0; i < n; i++){
        if(deuConflito(v[i], e)){
            return 0;
        }
    }
    return 1;
}

void ordenaDataSelectionSort(struct evento *evento, int n){
    int i, i_menor, j;
    for(i = 0; i<n-1; i++){
        i_menor = 1;
        for(j = i+1; j<n; j++){
            if(comopara)
        }
    }
}

void mostraEventos(struct evento evento){
    printf("\n------------------------\n");
    printf("Data:________%2i/%2i/%4i\n", evento.dataEvento.dia, evento.dataEvento.mes, evento.dataEvento.ano);
    printf("Inicio:______%2i:%2i\n", evento.horarioInicio.hora, evento.horarioInicio.minuto);
    printf("Fim:_________%2i:%2i\n", evento.horarioFim.hora, evento.horarioFim.minuto);
    printf("Descricao:___%s\n", evento.descricao);
    printf("Local:_______%s\n", evento.local);
}

int comparaData(struct data dataEvento, struct data dataBuscada){
    if(dataEvento.ano==dataBuscada.ano){
        if(dataEvento.mes==dataBuscada.mes){
            if(dataEvento.dia==dataBuscada.dia){
                return 1;
            }
        }
    }
    return 0;
}

int joga_pro_final(struct evento *evento, int n, int a, int m, int d, int h){
    int i;
    struct evento aux;

    for(i = 0; i<n; i++){
        if(evento[i].dataEvento.ano == a){
            if(evento[i].dataEvento.mes == m){
                if(evento[i].dataEvento.dia == d){
                    if(h >=evento[i].horarioInicio.hora && h <= evento[i].horarioFim.hora){
                        aux = evento[i];
                        evento[i] = evento[i+1];
                        evento[i+1] = aux;
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

int comparadorDeHora(struct horario x, struct horario y){
    if(x.hora>y.hora){
        return 1;
    }
    if(x.hora<y.hora){
        return -1;
    }
    
    return x.minuto-y.minuto;
}

int deuConflito(struct evento x, struct evento y){
    if(x.dataEvento.ano==y.dataEvento.ano
    &&x.dataEvento.mes==y.dataEvento.mes
    &&x.dataEvento.dia==y.dataEvento.dia){
        if(comparadorDeHora(x.horarioInicio, y.horarioInicio)==0
        ||comparadorDeHora(x.horarioFim, y.horarioFim)==0){
            return 1;
        }else{
            if(comparadorDeHora(x.horarioInicio, y.horarioInicio)>0
            &&comparadorDeHora(x.horarioInicio, y.horarioFim)<0){
                return 1;
            }else if(comparadorDeHora(y.horarioInicio, x.horarioInicio)>0
                    &&comparadorDeHora(y.horarioInicio, x.horarioFim)<0){
                        return 1;
            }else{
                return 0;
            }
        }
    }
    return 0;
}