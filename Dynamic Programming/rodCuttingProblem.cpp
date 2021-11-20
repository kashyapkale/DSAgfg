//https://practice.geeksforgeeks.org/problems/rod-cutting0840/1
int cutRodUtil(int price[], int length[], int n, int max_len,vector<vector<int>> &dp) {
        if(dp[n][max_len]!=-1)
            return dp[n][max_len];
        
        if (max_len == 0 || n == 0)
                return dp[n][max_len] = 0;
        
        int opt1 = INT_MIN;
        if (length[n - 1] <= max_len)
                opt1 = price[n - 1] + cutRodUtil(price, length, n, max_len - length[n - 1],dp);

        int opt2 = cutRodUtil(price, length, n - 1, max_len,dp);

        return dp[n][max_len] = max(opt1, opt2);
}


int cutRod(int price[], int n){
        int length[n];
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        for (int i = 0; i < n; i++) {
                length[i] = i + 1;
        }
        return cutRodUtil(price, length, n, n,dp);
}
