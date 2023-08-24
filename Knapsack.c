// solution for 0-1 Knapsack problem
#include <stdio.h>
// A utility function that returns maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }

// Returns the maximum value that can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{
	int v[n + 1][W + 1];
	// Build table v[][] in bottom up manner
	for (int i = 0; i <= n; i++) {
		for (int j= 0; j <= W; j++) {
			if (i == 0 || j == 0)
				v[i][j] = 0;
			else if (wt[i - 1] <= j)
				v[i][j] = max(val[i - 1]+ v[i - 1][j- wt[i - 1]],v[i - 1][j]);
			else
				v[i][j] = v[i - 1][j];
		}
	}

	return v[n][W];
}
int main()
{
	int profit[] = { 60, 100, 120 };
	int weight[] = { 10, 20, 30 };
	int W = 50;
	int n = sizeof(profit) / sizeof(profit[0]);
	printf("%d", knapSack(W, weight, profit, n));
	return 0;
}
