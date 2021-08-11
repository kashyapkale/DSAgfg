//https://practice.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1#
vector <int> countDistinct(int arr[], int n, int k){
    //code here.
    unordered_map<int, int> umap;
    //set<int> s;
    int distinct_count = 0;
    vector<int> ans;

    for (int m = 0; m < k; m++) {
        if (!umap[arr[m]])
            distinct_count++;
        umap[arr[m]]++;
    }
    ans.push_back(distinct_count);
    int i = 1, j = k;

    while (j < n) {
        umap[arr[i - 1]]--;
        if (!umap[arr[i - 1]])
            distinct_count--;

        if (!umap[arr[j]] && distinct_count < k){
            distinct_count++;
        }
        umap[arr[j]]++;
        ans.push_back(distinct_count);
        i++;
        j++;
    }
    return ans;
}
