#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "solve.h"
#define ERROR (-1)
#define CHAR_SIZE 256

int main(int argc, char **argv)
{
	char **a = 0;
	int res_read, spaces[CHAR_SIZE];
	int m, n, i, j, k;

	if( argc!=7 || sscanf(argv[2], "%d", &m)!=1 || sscanf(argv[3], "%d", &n)!=1 || sscanf(argv[4], "%d", &i)!=1 || sscanf(argv[5], "%d", &j)!=1 || m<1 || n<1 || i<0 || j<0 || i>=m || j>=m )
	{
		fprintf(stderr, "Usage: t m n i j a\t(m>0, n>0, 0<=i<m, 0<=j<m)\n");
		return ERROR;
	}

	if( !(a = (char **)malloc(m*n*sizeof(char *))) )
	{
		fprintf(stderr, "Can not allocate memory!\n");
		return ERROR;
	}

	for( k = 0; k<CHAR_SIZE; k++ )
		spaces[k] = 0;
	for( k = 0; argv[1][k]!='\n' && argv[1][k]!='\0'; k++ )
		spaces[(int)argv[1][k]] = 1;
	spaces[(int)'\n'] = 1;
	spaces[(int)'\0'] = 1;

	res_read = read_matrix(argv[6], spaces, a, m, n);
	if( res_read!=MATRIX_SUCCESS )
	{
		switch( res_read )
		{
			case MATRIX_ERROR_ALLOCATE:
				fprintf(stderr, "Can not allocate memory!\n");
				break;
			case MATRIX_ERROR_OPEN:
				fprintf(stderr, "Can not open %s!\n", argv[6]);
				break;
			default:
				fprintf(stderr, "Unknown error with code %d\n", res_read);
		}

		free(a);
		return ERROR;
	}

	printf("Input matrix:\n\n");
	print_matrix(a, m, n);
	solve(a, n, i, j);
	printf("Result:\n\n");
	print_matrix(a, m, n);

	delete_matrix(a, m*n);
	free(a);
	return 0;
}
