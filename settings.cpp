#include "headings.h"

//The function checks the row, column, diagonal 
int checkValid(int Q[], int k, int n)
{
	if (Q[k] < 1 || Q[k] > n)
		{
			return 0; //Check the column
		}             //The column < 1 or > n = 
	int i;
	for (i = 1; i < k; i++)
		{
			if (Q[k] == Q[i] ||/*Check column*/
				Q[k] + k == Q[i] + i ||/*Check diagonal(parallel main)*/
				Q[k] - k == Q[i] - i /*Check diagonal (parallel ... i don't know how to debscribe it, so you can think :))')*/)
				{
					return 0; //And it's over !
				}
		}
	return 1; //We can use this solution !
}
int solveQueens(int Q[], int &k, int n)
{
	if (checkValid(Q, k, n))
		{
			if (k == n)
				{
					return 1; // Completing a solution !
				};
			k++; //Take the next queen.
			Q[k] = 1; //Set it's position = 1 first.
			return solveQueens(Q, k, n);
		}
	else 
		{
			if (Q[k] > n) //Check all the column of this row and no position's proper.
				{
					k--; // Turn back the previous queen
				}
			if (k < 1) // If we check all the queens
				{
					return 0; // The solution's wrong, and we have to try another solution !
				}
			Q[k]++; // Check the next position for the queen;
			return solveQueens(Q, k, n); //Continue finding the next queen on new row
		}
}
void printSol(int Q[], int k, int n)
{
	int i;
	for (i = 1; i <= k; i++)
		{
			printf("%d ", Q[i]);
		}
}
