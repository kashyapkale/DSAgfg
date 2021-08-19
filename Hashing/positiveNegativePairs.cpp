//https://practice.geeksforgeeks.org/problems/positive-negative-pair5209/1/?track=DSASP-Hashing&batchId=274#
vector <int> findPairs(int arr[], int n){
    unordered_map<int, int> umap;
    vector<int> ans;

    for (int i = 0; i < n; i++) {
        if (umap.find(abs(arr[i])) == umap.end())
            umap[abs(arr[i])] = (arr[i] < 0)?-11:11;

        else if (umap[abs(arr[i])] != 0) {
            if ((umap[abs(arr[i])] > 0 && arr[i] < 0) || (umap[abs(arr[i])] < 0 && arr[i] > 0))
                umap[abs(arr[i])] = 0;

            if (umap[abs(arr[i])] == 0) {
                ans.push_back(abs(arr[i]) * -1);
                ans.push_back(abs(arr[i]));
            }
        }
    }

    return ans;
}
