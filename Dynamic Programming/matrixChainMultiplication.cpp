//https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1#
int MCM(int arr[],int i,int j,int dp[][505]){
        if(i>=j)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        int minimum = INT_MAX;
        for(int k=i;k<=j-1;k++){
            int temp = MCM(arr,i,k,dp) + MCM(arr,k+1,j,dp) + (arr[i-1]*arr[k]*arr[j]);
            minimum = min(minimum,temp);
        }
        
        return dp[i][j] = minimum;
    
    }


    int matrixMultiplication(int N, int arr[])
    {
        //int dp[N+1][N+1];
        int dp[505][505];
        memset(dp,-1,sizeof(dp));   
        return MCM(arr,1,N-1,dp);
    }
