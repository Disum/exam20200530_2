#include "solve.h"

void solve(char **a, int n, int i, int j)
{
	int k;
	char *buff;

	for( k = 0; k<n; k++ )
	{
		if( !a[i*n + k] && !a[j*n + k])
			break;
		buff = a[i*n + k];
		a[i*n + k] = a[j*n + k];
		a[j*n + k] = buff;
	}
}
