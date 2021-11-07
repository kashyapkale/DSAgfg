//https://practice.geeksforgeeks.org/problems/subset-sum-problem2643/0/
bool isSubsetSumUtil(int N, int arr[], int sum, vector<vector<int> > &dp){
    if (sum == 0)
        return true;

    if (N == 0)
        return false;
    if (sum < 0)
        return false;

    if (dp[N - 1][sum] != -1) {
        return (dp[N - 1][sum] == 1)?true:false;
    }
    bool res = isSubsetSumUtil(N - 1, arr, sum - arr[N - 1], dp) || isSubsetSumUtil(N - 1, arr, sum, dp);

    dp[N - 1][sum] = (res)?1:0;
    return res;

}

bool findPartition(int a[], int N){
    int sum = 0;

    for (int i = 0; i < N; i++) {
        sum += a[i];
    }
    if (sum % 2 != 0)
        return false;
    sum = sum / 2;
    vector<vector<int> > dp(N + 1, vector<int>(sum + 1, -1));

    return isSubsetSumUtil(N, a, sum, dp);
}
