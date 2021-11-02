//https://practice.geeksforgeeks.org/problems/wildcard-pattern-matching/1

int wildCardUtil(string &str1, string &str2, int j, int i, vector<vector<int> > &dp){
    //cout<<i<<" "<<j<<endl;

    if (j == str1.length() && i == str2.length())
        return 1;
    if (j == str1.length()) {
        return 0;
    }

    if ((i == str2.length())) {
        while (j < str1.length()) {
            if (str1[j] != '*') {
                return 0;
            }
            j++;
        }
        return 1;
    }

    if (dp[j][i] != -1)
        return dp[j][i];
    if (str1[j] == str2[i] || str1[j] == '?')
        return dp[j][i] = wildCardUtil(str1, str2, j + 1, i + 1, dp);
    else if (str1[j] == '*') {
        if (j + 1 == str1.length())
            return dp[j][i] = 1;

        while (i < str2.length()) {
            if (wildCardUtil(str1, str2, j + 1, i, dp)) {
                return dp[j][i] = 1;
            }
            i++;
        }
    }
    return dp[j][i] = 0;
}


int wildCard(string pattern, string str){
    vector<vector<int> > dp(pattern.length() + 1, vector<int>(str.length() + 1, -1));

    return wildCardUtil(pattern, str, 0, 0, dp);
}
