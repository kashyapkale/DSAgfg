//https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
//My Solution is a bit complicated , simpler version available
int dp[1005][1005];
int solution(int W, int wt[], int val[], int n) {
	if (W <= 0)
		return 0;

	if (dp[n][W] != -1) {
		//cout<<dp[n][W]<<endl;
		return dp[n][W];
	}


	int max_profit = 0;
	for (int i = 0; i < n; i++) {
		if (wt[i] <= W) {
			int profit = solution(W - wt[i], wt + i + 1, val + i + 1, n - i - 1) + val[i];
			max_profit = max(profit, max_profit);
		}

	}
	//cout<<max_profit<<endl;
	return dp[n][W] = max_profit;
	//return max_profit;
}


int knapSack(int W, int wt[], int val[], int n)
{

	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= W + 1; j++) {
			dp[i][j] = -1;
		}
	}
	return solution(W, wt, val, n);

}
