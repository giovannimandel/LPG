#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **aloca_matriz( int l, int c );
void gera_valores( int **p, int l, int c );
void mostra_matriz( int **p, int l, int c, char id );
void libera_matriz( int **p, int l );

int **inicializa_matriz( int *pl, int *pc, char id );
int **soma_matrizes( int **p1, int l1, int c1, int **p2, int l2, int c2 );

int main(int argc, char *argv[]) {
	int **a, lin_a, col_a;
	int **b, lin_b, col_b;
	
	a = inicializa_matriz( &lin_a, &col_a, 'A' );	
	b = inicializa_matriz( &lin_b, &col_b, 'B' );
	
	// Mostra matrizes na tela.
	mostra_matriz( a, lin_a, col_a, 'A' );
	mostra_matriz( b, lin_b, col_b, 'B');
	
	int **c = soma_matrizes( a, lin_a, col_a, b, lin_b, col_b );
	
	if( c == NULL)
		printf("Matrizes incompativeis!\n");
	else{
		mostra_matriz( c, lin_a, col_a, 'C' );
		libera_matriz( c, lin_a );
	}
	
	// Libera a memoria
	libera_matriz( a, lin_a );
	libera_matriz( b, lin_b );
	
	return 0;
}

int **aloca_matriz( int l, int c ){
	int i, j;
	
	int **p = malloc( sizeof(int*) * l );
	for( i = 0 ; i < l ; i++ )
		p[i] = malloc( sizeof(int) * c );

	return p;
}

void gera_valores( int **p, int l, int c ){
	int i, j;
	// Entrada de dados (geracao de numeros aleatorios)
	srand( time(0) );
	for( i = 0 ; i < l ; i++ )
		for( j = 0 ; j < c ; j++ )
			p[i][j] = rand() % 10000;
}

void mostra_matriz( int **p, int l, int c , char id ){
	int i, j;
	printf("\nDados da matriz %c (%dx%d):\n", id, l, c);
	for( i = 0 ; i < l ; i++ ){
		for( j = 0 ; j < c ; j++ )
			printf("%4d ", p[i][j]);
		printf("\n");
	}
	printf("----------------------------------------\n");
}

void libera_matriz( int **p, int l ){
	int i;
	for( i = 0 ; i < l ; i++ )
		free( p[i] );
	free( p );
}

int **inicializa_matriz( int *pl, int *pc, char id ){
	printf("Entrada da matriz %c:\n", id);
	printf("Quantas linhas? ");
	scanf("%d", pl);
	printf("Quantas colunas? ");
	scanf("%d", pc);
	int **p = aloca_matriz( *pl, *pc );
	gera_valores( p, *pl, *pc );
	
	return p;
}

int **soma_matrizes( int **p1, int l1, int c1, int **p2, int l2, int c2 ){
	int i, j;
	
	if( l1 != l2 || c1 != c2 ) // Incompativeis!
		return NULL;
	
	int **p = aloca_matriz( l1, c1 );
	
	for( i = 0 ; i < l1 ; i++ )
		for( j = 0 ; j < c1 ; j++ )
			p[i][j] = p1[i][j] + p2[i][j];

	return p;
}

