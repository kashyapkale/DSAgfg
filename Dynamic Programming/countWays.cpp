//https://practice.geeksforgeeks.org/problems/count-number-of-hops-1587115620/0/
long long countWaysUtil(int n, vector<long long> &dp){

    if (n == 0)
        return 1;

    if (n < 0)
        return 0;

    if (dp[n] != -1)
        return dp[n];

    long long ans = 0;

    for (int i = 1; i <= 3; i++)
        ans += countWaysUtil(n - i, dp);

    return dp[n] = ans % 1000000007;
    //return ans;

}

long long countWays(int n){
    vector<long long> dp(n + 1, -1);

    return countWaysUtil(n, dp);
}
