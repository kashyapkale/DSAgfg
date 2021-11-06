//https://practice.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter1322/0
int countWaysUtil(int n,vector<int> &dp){
    
    
    if (n == 0)
        return 1;

    if (n < 0)
        return 0;
    
    if (dp[n]!=-1)
        return dp[n];
        
    long long ans = 0;

    for (int i = 1; i <= 2; i++)
            ans += countWaysUtil(n - i,dp);

    return dp[n] = ((ans/2)+1)%1000000007;
    //return ans;

}

int countWays(int n){
    vector<int> dp(n+1,-1);
    return countWaysUtil(n,dp);
}
