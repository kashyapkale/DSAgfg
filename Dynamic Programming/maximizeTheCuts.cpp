//https://practice.geeksforgeeks.org/problems/cutted-segments1642/1#
int maximizeTheCutsSol(int n, int x, int y, int z,int dp[])
    {
        if(n==0)
            return 0;
        if(n<0)
            return INT_MIN;
        if(dp[n]!=-1)
            return dp[n];
            
            
        return dp[n] = 1 + max(maximizeTheCutsSol(n-x,x,y,z,dp),max(maximizeTheCutsSol(n-y,x,y,z,dp),maximizeTheCutsSol(n-z,x,y,z,dp)));
    }
    
    int maximizeTheCuts(int n, int x, int y, int z){
            int dp[n+1];
            memset(dp,-1,sizeof(dp));
            return max(maximizeTheCutsSol(n,x,y,z,dp),0);
    }
