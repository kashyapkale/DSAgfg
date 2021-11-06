//https://practice.geeksforgeeks.org/problems/ncr-1587115620/0
int nCrUtil(int n, int r,vector<vector<int>> &dp){
  if (r == 0 || r == n)
    return 1;
  if (n < r)
    return 0;
if(dp[n][r]!=-1)
    return dp[n][r];
  return dp[n][r] = (nCrUtil(n - 1, r - 1,dp) + nCrUtil(n - 1, r,dp)) % 1000000007;
}

int nCrModp(int n, int r){
  vector<vector<int>> dp(n+1,vector<int>(r+1,-1));    
  return nCrUtil(n, r,dp);

}
