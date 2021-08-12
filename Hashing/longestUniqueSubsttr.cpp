//https://practice.geeksforgeeks.org/problems/length-of-the-longest-substring3036/1
//Special Note : Unordered Map did not work for hashing purpose , Thus I used Vector for hashing purpose , Ascii value of chars was used for indexing/keys.
int longestUniqueSubsttr(string S){
        if (S.size() == 0) return 0;
        vector<int> umap(300,0);
        //int cnt = 0;
        int maximum = INT_MIN;
        int i = 0, j = 0;

        while (j < S.length()) {
                umap[S[j]]++;
                //cnt++;
                if (umap[S[j]] > 1) {
                        while (S[i] != S[j]) {
                                umap[S[i]]--;
                                i++;
                        }
                        umap[S[i]]--;
                        i++;
                }

                maximum = max(maximum, (j - i + 1));
                j++;
        }

        return maximum;

}
