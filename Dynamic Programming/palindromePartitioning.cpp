//https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1

//2.6 Secs
bool isPalindrome(string &s, int i, int j){
    while (i <= j) {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int palindromicPartitionUtil(string &s, int i, int j, vector<vector<int> > &dp){
    if (i >= j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (isPalindrome(s, i, j))
        return 0;

    int minCuts = INT_MAX;

    for (int k = i; k <= j - 1; k++) {
        int cuts = 1 + palindromicPartitionUtil(s, i, k, dp) + palindromicPartitionUtil(s, k + 1, j, dp);
        minCuts = min(minCuts, cuts);
    }

    return dp[i][j] = minCuts;

}


int palindromicPartition(string str){
    int len = str.size();
    vector<vector<int> > dp(len + 1, vector<int>(len + 1, -1));

    return palindromicPartitionUtil(str, 0, str.size() - 1, dp);
}




//******************************************************************************************************************************
//More Optimised Version given below

//1.2 Secs
bool isPalindrome(string &s, int i, int j){
    while (i <= j) {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int palindromicPartitionUtil(string &s, int i, int j, vector<vector<int> > &dp){
    if (i >= j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (isPalindrome(s, i, j))
        return 0;

    int minCuts = INT_MAX;

    for (int k = i; k <= j - 1; k++) {

        int leftCut = dp[i][k];
        int rightCut = dp[k + 1][j];
        
        if (leftCut == -1)
            leftCut = palindromicPartitionUtil(s, i, k, dp);
        if (rightCut == -1)
            rightCut = palindromicPartitionUtil(s, k + 1, j, dp);

        int cuts = 1 + leftCut + rightCut;
        minCuts = min(minCuts, cuts);
    }

    return dp[i][j] = minCuts;

}


int palindromicPartition(string str){
    int len = str.size();
    vector<vector<int> > dp(len + 1, vector<int>(len + 1, -1));

    return palindromicPartitionUtil(str, 0, str.size() - 1, dp);
}
