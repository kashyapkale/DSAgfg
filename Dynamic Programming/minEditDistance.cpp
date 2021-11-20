//https://practice.geeksforgeeks.org/problems/edit-distance3702/1#
int editDistanceUtil(string s, string t, vector<vector<int> > &dp) {
    int N1 = s.length();
    int N2 = t.length();

    if (N1 == 0) {
            return N2;
    }

    if (N2 == 0) {
            return N1;
    }

    if (dp[N1][N2] != -1)
        return dp[N1][N2];

    if (s[0] == t[0])
        return dp[N1][N2] = editDistanceUtil(s.substr(1,N1-1), t.substr(1, N2-1), dp);

    //Insert
    string S1 = s.substr(0, N1);
    string S2 = t.substr(1,N2-1);
    int opt1 = editDistanceUtil(S1,S2,dp);
    
    //Delete
    S1 = s.substr(1, N1 - 1);
    S2 = t;
    int opt2 = editDistanceUtil(S1,S2,dp);
    
    //Replace
    S1 = s.substr(1,N1-1);
    S2 = t.substr(1,N2-1);
    int opt3 = editDistanceUtil(S1,S2,dp);

    return dp[N1][N2] = 1 + min(min(opt1,opt2),opt3);
}

int editDistance(string s, string t){
    int N;
    N = max(s.length(),t.length());
    vector<vector<int> > dp(N + 1, vector<int>(N + 1, -1));
    return editDistanceUtil(s, t, dp);
}
