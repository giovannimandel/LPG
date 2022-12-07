//ALUNOS: 
//        CÉSAR EDUARDO DE SOUZA
//        JOÃO PEDRO PATRÍCIO DO NASCIMENTO

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <math.h>
#include <string.h>

//structs
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

//functions

//1
int insereEvento(struct evento *evento);
int checaData(struct data data);
int checaHora(struct horario inicio, struct horario fim);
void ordenaDataSelectionSort(struct evento *evento, int n);

int verificaConsistencia(struct evento *v, int n, struct evento e);
int deuConflito(struct evento x, struct evento y);
int comparadorDeHora(struct horario x, struct horario y);
//2
void mostraEventos(struct evento evento);
//3
int comparaData(struct data dataEvento, struct data dataBuscada);
void insereData(struct data *data);
//4
int joga_pro_final(struct evento *evento, int n, int a, int m, int d, int h);


int main(){
    setlocale(LC_ALL, "Portuguese");

    int opcao, totalEventos=0, contador=0, h;
    struct evento *eventos = NULL;
    struct data dataBuscada, dataBuscada2;
    struct evento eventoA;
    
    FILE *f;
	
	f = fopen( "cadastro.txt", "rt" );
	if( f != NULL){
		
		fscanf( f , "%d", &totalEventos);
		eventos = malloc( sizeof(struct evento) * totalEventos);
		
		for(int i=0;i<totalEventos;i++){
			
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
		fclose( f );
		printf("%d registros carregados com sucesso!\n", totalEventos);
	}
    
    do{
        printf("\n>>>>>>>>>Agenda de Eventos<<<<<<<<<\n1- Cadastrar\n2-Mostrar todos os eventos da agenda\n3-Mostrar todos os eventos de uma data\n4-Mostrar todos os eventos que tenham uma descrição\n5-Remover evento\n6-Sair\n");
        scanf(" %i", &opcao);

        switch (opcao){
        case 1:
            printf("\nInserir evento:\n");
        


            if(insereEvento(&eventoA)){
                if(verificaConsistencia(eventos, totalEventos, eventoA)){
                    totalEventos++;
                    eventos = realloc(eventos, sizeof(struct evento)*totalEventos);
                    eventos[totalEventos-1] = eventoA;
                }else{
                    printf("\nConflito existente no evento\n");
                }
            }else{
                printf("\nFalha ao adicionar evento(Data ou hora inválidas)\n");
            }

            if(totalEventos>1){
                ordenaDataSelectionSort(eventos, totalEventos);
            }
            break;
        case 2:
            if(totalEventos>0){
                for(int i = 0; i<totalEventos; i++){
                    printf("\nEvento %i", i+1);
                    mostraEventos(eventos[i]);
                }
            }else{
                printf("\nNão há eventos\n");
            }

            break;
        case 3:
            if(totalEventos>0){
                printf("\nBuscar por data:\n");
                printf("\nInsira a data que deseja buscar:\n");
                insereData(&dataBuscada);

                for(int i=0; i<totalEventos; i++){
                    if(comparaData(eventos[i].dataEvento, dataBuscada)){
                        printf("\nEvento encontrado:\nEvento %i", i+1);
                        mostraEventos(eventos[i]);
                        contador++;
                    }
                }
                if(contador==0){
                    printf("\nNão há eventos nessa data.\n");
                }
                contador=0;
            }else{
                printf("\nNão há eventos\n");
            }

            break;
        case 4:
            if(totalEventos>0){
                char descricaoBuscada[20];
                printf("\nInsira a descrição do evento buscado.\n");
                scanf(" %[^\n]", descricaoBuscada);
                printf("Descrição buscada:\t%s", descricaoBuscada);

                contador = 0;
                for(int i=0; i<totalEventos; i++){
                    if(strcmp(eventos[i].descricao, descricaoBuscada)==0){
                        printf("\nEvento encontrado:\n");
                        mostraEventos(eventos[i]);
                        contador++;
                    }
                }
                if(contador==0){
                    printf("\nNão há eventos com essa descrição\n");
                }
            }else{
                printf("\nNão há eventos.\n");
            }

            break;
        case 5:
            if(totalEventos>0){
                printf("Remover Evento Por Data");
			
			    insereData(&dataBuscada2);
			    printf("Digite a Hora: ");
			    scanf("%i", &h);
			
			    if(joga_pro_final(eventos, totalEventos, dataBuscada2.ano, dataBuscada2.mes, dataBuscada2.dia, h)){
                    totalEventos--;
			        eventos = realloc(eventos, sizeof(struct evento)*totalEventos);
                    ordenaDataSelectionSort(eventos, totalEventos);
                }
                ordenaDataSelectionSort(eventos, totalEventos);
            }else{
                printf("\nNão há eventos.\n");
            }
            break;
        }

    }while(opcao!=6);

	f = fopen( "cadastro.txt", "wt" );
	fprintf( f, "%d\n", totalEventos);
	
	for(int i=0;i<totalEventos;i++){
		fprintf(f, "%i\n%i\n%i\n", eventos[i].dataEvento.dia, eventos[i].dataEvento.mes, eventos[i].dataEvento.ano);
		fprintf(f, "%i\n%i\n", eventos[i].horarioInicio.hora, eventos[i].horarioInicio.minuto);
		fprintf(f, "%i\n%i\n", eventos[i].horarioFim.hora, eventos[i].horarioFim.minuto);
		fprintf(f, "%s\n%s\n", eventos[i].descricao, eventos[i].local);
	}
	
	fclose(f);

    printf("Saindo do programa...\nDesenvolvido por João & César ®\n");
    free(eventos);
    return 0;
}

int insereEvento(struct evento *evento){
//data    
    insereData(&evento->dataEvento);
    if(checaData(evento->dataEvento)!=1){
        return 0;
    }
   
//hora
    printf("\n\nHora de início:\n");
    scanf(" %i", &evento->horarioInicio.hora);
    printf("\nMinuto de início:\n");
    scanf(" %i", &evento->horarioInicio.minuto);
    printf("\n\nHora de fim:\n");
    scanf(" %i", &evento->horarioFim.hora);
    printf("\nMinuto de fim:\n");
    scanf(" %i", &evento->horarioFim.minuto);
    
    if(checaHora(evento->horarioInicio, evento->horarioFim)!=1){
        return 0;
    }

//strings
    printf("\n\nDescrição do evento:\n");
    scanf(" %[^\n]", evento->descricao);
    printf("\n\nLocal:\n");
    scanf(" %[^\n]", evento->local);

    return 1;
}

void mostraEventos(struct evento evento){
    printf("\n------------------------\n");
    printf("Data:________%2i/%2i/%4i\n", evento.dataEvento.dia, evento.dataEvento.mes, evento.dataEvento.ano);
    printf("Início:______%2i:%2i\n", evento.horarioInicio.hora, evento.horarioInicio.minuto);
    printf("Fim:_________%2i:%2i\n", evento.horarioFim.hora, evento.horarioFim.minuto);
    printf("Descrição:___%s\n", evento.descricao);
    printf("Local:_______%s\n", evento.local);
}

int checaData(struct data data){
    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    
    printf("Data atual: %d/%d/%d/\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

    if(data.ano<tm.tm_year + 1900){
        printf("\nImpossível adicionar eventos para anos passados.\n");
        return 0;
    }else if(data.ano==tm.tm_year + 1900&&data.mes<tm.tm_mon + 1){
        printf("\nImpossível adicionar eventos para meses passados nesse ano.\n");
        return 0;
    }else if((data.ano==tm.tm_year + 1900)&&(data.mes==tm.tm_mon + 1)&&(data.dia<tm.tm_mday)){
        printf("\nEsse dia já passou.\n");
        return 0;
    }
    
    int bissexto = 0;
    if((data.ano%400==0)||(data.ano%4==0&&data.ano%100!=0)){
        bissexto = 1;
    }
    
    if(data.mes>12||data.mes<1){
        printf("\nMês inválido (Aceitos:\t1,2,...,11,12)\n");
        return 0;
    }else if(data.mes%2==0){
        if(bissexto){
            if((data.mes==2)&&(data.dia>28)){
                printf("\nEste ano é bissexto\n");
                return 0;
            }
        }
        if(data.dia>30){
                printf("\nDia inválido\n");
                return 0;
        }
    }else if(data.dia>31){
        printf("\nDia inválido\n");
        return 0;
    }

    if(data.dia<1){
        printf("\nData inválida\n");
        return 0;
    }
    
    return 1;
}

int checaHora(struct horario inicio, struct horario fim){
    if(inicio.hora<0||inicio.hora>23||fim.hora<0||fim.hora>24){
        printf("\nErro em 'hora'\n");
        return 0;
    }
    if(inicio.minuto<0||inicio.minuto>59||fim.minuto<0||fim.minuto>59){
        printf("\nErro em 'minuto'\n");
        return 0;
    }
    
    if(inicio.hora>fim.hora){
        printf("\nEvento não pode iniciar depois de seu fim.\n");
        return 0;
    }
    if(inicio.hora==fim.hora){
        if(inicio.minuto>fim.minuto){
            printf("\nEvento não pode iniciar depois de seu fim.\n");
            return 0;
        }
    }
    return 1;
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

void insereData(struct data *data){
    printf("\nDia:\t");
    scanf("%d", &data->dia);
    printf("\nMês:\t");
    scanf("%d", &data->mes);
    printf("\nAno:\t");
    scanf("%d", &data->ano);
}

int joga_pro_final(struct evento *evento, int n, int a, int m, int d, int h){
	
	int i;
	struct evento aux;
	
	for(i=0;i<n;i++){
		if(evento[i].dataEvento.ano == a){
			if(evento[i].dataEvento.mes == m){
				if(evento[i].dataEvento.dia == d){
					if(h >= evento[i].horarioInicio.hora && h <= evento[i].horarioFim.hora){
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

void ordenaDataSelectionSort(struct evento *evento, int n){
   int menor;
   struct evento troca;

    for(int i=0; i<n-1; i++){
        menor = i;
        for(int j=i+1; j<n; j++){
            if(evento[j].dataEvento.ano<evento[menor].dataEvento.ano){
            menor=j;
            }
        }

        if(i!=menor){
            troca = evento[i];
            evento[i] = evento[menor];
            evento[menor] = troca; 
        }
    }
//Se o ano for igual:
    for(int u=0; u<n; u++){
        for(int v=0; v<n; v++){
            if(evento[u].dataEvento.ano==evento[v].dataEvento.ano){

                for(int i=0; i<n-1; i++){
                    menor = i;
                    for(int j=i+1; j<n; j++){
                        if(evento[j].dataEvento.mes < evento[menor].dataEvento.mes){
                        menor=j;
                        }
                    }
                    
                    if(i!=menor){
                    troca = evento[i];
                    evento[i] = evento[menor];
                    evento[menor] = troca; 
                    }
                }

            }
        }
    }
//Se o ano e o mês forem iguais:
    for(int u=0; u<n; u++){
        for(int v=0; v<n; v++){
            if(evento[u].dataEvento.ano==evento[v].dataEvento.ano
            &&evento[u].dataEvento.mes==evento[v].dataEvento.mes){

                for(int i=0; i<n-1; i++){
                    menor = i;
                    for(int j=i+1; j<n; j++){
                        if(evento[j].dataEvento.dia < evento[menor].dataEvento.dia){
                        menor=j;
                        }
                    }
                    
                    if(i!=menor){
                    troca = evento[i];
                    evento[i] = evento[menor];
                    evento[menor] = troca; 
                    }
                }

            }
        }
    }

//Se o ano, o mês e o dia forem iguais
    for(int u=0; u<n; u++){
        for(int v=0; v<n; v++){
            if(evento[u].dataEvento.ano==evento[v].dataEvento.ano
            &&evento[u].dataEvento.mes==evento[v].dataEvento.mes
            &&evento[u].dataEvento.dia==evento[v].dataEvento.dia){

                for(int i=0; i<n-1; i++){
                    menor = i;
                    for(int j=i+1; j<n; j++){
                        if(evento[j].horarioInicio.hora < evento[menor].horarioInicio.hora){
                        menor=j;
                        }
                    }
                    
                    if(i!=menor){
                    troca = evento[i];
                    evento[i] = evento[menor];
                    evento[menor] = troca; 
                    }
                }

            }
        }
    }
//Se o ano, o mês, o dia e a hora forem iguais
    for(int u=0; u<n; u++){
        for(int v=0; v<n; v++){
            if(evento[u].dataEvento.ano==evento[v].dataEvento.ano
            &&evento[u].dataEvento.mes==evento[v].dataEvento.mes
            &&evento[u].dataEvento.dia==evento[v].dataEvento.dia
            &&evento[u].horarioInicio.hora==evento[v].horarioInicio.hora){
                
                for(int i=0; i<n-1; i++){
                    menor = i;
                    for(int j=i+1; j<n; j++){
                        if(evento[j].horarioInicio.minuto < evento[menor].horarioInicio.minuto){
                        menor=j;
                        }
                    }
                    
                    if(i!=menor){
                    troca = evento[i];
                    evento[i] = evento[menor];
                    evento[menor] = troca; 
                    }
                }

            }
        }    
    }
}

int verificaConsistencia(struct evento *v, int n, struct evento e){
    for(int i = 0; i<n; i++){
        if(deuConflito(v[i], e)){
           return 0; 
        }
    }
    return 1;
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

int comparadorDeHora(struct horario x, struct horario y){
    if(x.hora>y.hora){
        return 1;
    }
    if(x.hora<y.hora){
        return -1;
    }
    
    return x.minuto-y.minuto;
}
