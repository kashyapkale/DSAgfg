//https://practice.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/0
long long maximumAmountUtil(int arr[],int i, int j,vector<vector<int>> &dp){
        if (i+1 == j) {
                return max(arr[i],arr[j]);
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        return dp[i][j] = max((arr[i] + min(maximumAmountUtil(arr, i + 1, j - 1,dp), maximumAmountUtil(arr, i + 2, j,dp))), (arr[j] + min(maximumAmountUtil(arr,i + 1, j - 1,dp), maximumAmountUtil(arr,i, j - 2,dp))));
}


long long maximumAmount(int arr[], int n){
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return maximumAmountUtil(arr, 0, n - 1,dp);
}
