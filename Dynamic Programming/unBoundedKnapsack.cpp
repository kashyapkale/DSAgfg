//https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1#
//Same as 01 knapsack , only repetition of elements is allowed
//this is the simpler version of the previously written complex code for 01 Knapsack
int dp[1005][1005];
int solution(int W, int wt[], int val[], int n) {

	if (dp[n][W] != -1)
		return dp[n][W];


	if (n == 0 || W == 0)
		return dp[n][W] = 0;

	if (wt[n - 1] <= W)
		return dp[n][W] = max((val[n - 1]) + solution(W - wt[n - 1], wt, val, n), solution(W, wt, val, n - 1));

	return dp[n][W] = solution(W, wt, val, n - 1);


}



int knapSack(int N, int W, int val[], int wt[])
{

	for (int i = 0; i <= N + 1; i++) {
		for (int j = 0; j <= W + 1; j++) {
			dp[i][j] = -1;
		}
	}
	return solution(W, wt, val, N);

}
