#ifndef MATRIX_H
#define MATRIX_H

enum MATRIX_ERROR_CODES
{
	MATRIX_ERROR_OPEN,
	MATRIX_ERROR_ALLOCATE,
	MATRIX_SUCCESS
};

int read_matrix(char *name, int *spaces, char **a, int m, int n);
void delete_matrix(char **a, int len);
void print_matrix(char **a, int m, int n);

#endif
