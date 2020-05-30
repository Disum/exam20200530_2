#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#define MAX_LEN 1024

int read_matrix(char *name, int *spaces, char **a, int m, int n)
{
	FILE *input;
	int i, j, k, l;
	char buff[MAX_LEN];

	if( !(input = fopen(name, "r")) )
		return MATRIX_ERROR_OPEN;

	for( i = 0; i<m; i++ )
	{
		for( j = 0; j<n; j++ )
		{
			for( k = 0; k<MAX_LEN; k++ )
			{
				if( fscanf(input, "%c", buff + k)!=1 || spaces[(int)buff[k]] )
					break;
			}

			if( !(a[i*n + j] = (char *)malloc((k + 1)*sizeof(char))) )
			{
				delete_matrix(a, i*n + j - 1);
				return MATRIX_ERROR_ALLOCATE;
			}
			for( l = 0; l<k; l++ )
				a[i*n + j][l] = buff[l];
			a[i*n + j][k] = '\0';
		}
	}

	fclose(input);
	return MATRIX_SUCCESS;
}

void delete_matrix(char **a, int len)
{
	int i;

	for( i = 0; i<len; i++ )
		free(a[i]);
}

void print_matrix(char **a, int m, int n)
{
	int i, j;

	for( i = 0; i<m; i++ )
	{
		for( j = 0; j<n; j++)
			printf("%s\t", a[i*n + j]);

		printf("\n");
	}
}
