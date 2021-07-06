//https://practice.geeksforgeeks.org/problems/coin-change2448/1#
long long int Sol( int S[], int m, int n ,long long int dp[][1005]){
        if(n==0)
            return 1;
        if(n<0)
            return 0;
        /*if(n<0)
            return INT_MIN;*/
        /*if(dp[n]!=-1)
            return dp[n];*/
            
        if (m <=0 && n >= 1)
            return 0;    
        
        if(dp[n][m]!=-1)
            return dp[n][m];
        
        return dp[n][m] = Sol(S,m-1,n,dp) + Sol(S,m,n-S[m-1],dp);
        
        
    }
  
    long long int count( int S[], int m, int n )
    {
        long long int dp[1005][1005];
        memset(dp,-1,sizeof(dp));
        return Sol(S,m,n,dp);
        
    }
