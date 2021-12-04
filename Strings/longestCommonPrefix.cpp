//https://practice.geeksforgeeks.org/problems/longest-common-prefix-in-an-array5129/1
//Longest Common Prefix
string longestCommonPrefix(string arr[], int N){
    string maximum = "";
    int minLen = INT_MAX;

    for (int i = 0; i < N; i++) {
        int len = arr[i].length();
        minLen = min(len, minLen);
    }

    int k = 0;
    while (minLen--) {
        char prev = '$';
        for (int i = 0; i < N; i++) {
            char curr = arr[i][k];
            if(prev!='$'){
                if(prev != curr)
                    return (maximum=="")?"-1":maximum;             
            }
            prev = curr;
        }
        maximum+=arr[0][k];
        k++;
        
    }
    return (maximum=="")?"-1":maximum;
}
