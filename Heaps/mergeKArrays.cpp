//https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/0
vector<int> mergeKArrays(vector<vector<int> > arr, int K){
    int rows = K;
    //cout<<rows<<" are Rows"<<endl;
    int columns = K;
    //cout<<columns<<" are Columns"<<endl;
    vector<int> ans;
    priority_queue <mPair, vector<mPair>, greater<mPair> > minHeap;
    int j = 0;

    for (int i = 0; i < rows; i++) {
        minHeap.push(make_pair(arr[i][j], make_pair(i, j)));
    }

    while (!minHeap.empty()) {
        mPair temp = minHeap.top();
        minHeap.pop();
        ans.push_back(temp.first);
        temp.second.second++;
        if (temp.second.second < columns) {
            int x = temp.second.first;
            int y = temp.second.second;
            minHeap.push(make_pair(arr[x][y], make_pair(x, y)));
        }
    }

    return ans;
}
