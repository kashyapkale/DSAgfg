//https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1
//Maximum Increasing Subsequence
int maxSumIS(int arr[], int n){
	vector<int> dp(n, 0);

	dp[0] = arr[0];
	int ans = arr[0];

	for (int i = 1; i < n; i++) {
		int temp = -1;
		for (int j = 0; j <= i - 1; j++) {
			if (arr[i] > arr[j]) {
			    temp = (temp==-1)?dp[j]:max(dp[j],temp);
			}
		}
		dp[i] = (temp==-1)?arr[i]:temp+arr[i];
		ans = max(ans, dp[i]);
	}
	return ans;
}
