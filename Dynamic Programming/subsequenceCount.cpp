//https://practice.geeksforgeeks.org/problems/distinct-occurrences/1
int subsequenceCountUtil(string &Str1, string &Str2, int i, int j, vector<vector<int> > &dp){
  if (dp[i][j] != -1)
    return dp[i][j];


  if (j == Str2.length()) {
    return 1;
  }
  if (i == Str1.length()) {
    return 0;
  }
  long long ans = 0;


  if (Str1[i] == Str2[j]) {
    ans = subsequenceCountUtil(Str1, Str2, i + 1, j + 1, dp);
  }
  ans += subsequenceCountUtil(Str1, Str2, i + 1, j, dp);
  ans %= 1000000007;
  return dp[i][j] = ans;
  //return ans;
}



int subsequenceCount(string S, string T){
  vector<vector<int> > dp(S.length() + 1, vector<int>(T.length() + 1, -1));

  return subsequenceCountUtil(S, T, 0, 0, dp);
}
