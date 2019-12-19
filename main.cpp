#include "headings.h"

int main()
{
	int* Q;
	int n;
	printf("Enter the number queens: ");
	scanf("%d", &n);
	printf("\n");
	Q = (int*)malloc(n*sizeof(int));
	int k = 1;
	Q[1] = 1;
	int j = 0;
	while (solveQueens(Q, k, n))
		{
			printf("#Sol %d: ", ++j);
			printSol(Q, k, n);
			printf("\n");
			Q[k]++;
		}
	free(Q);
	return 0;
}
