//https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/0
//Minimum Spanning Tree - Prims Algorithm
int spanningTree(int V, vector<vector<int> > adj[]){
    vector<int> key(V + 1, INT_MAX);
    vector<bool> mst(V + 1, false);
    vector<int> parent(V + 1);

    parent[0] = -1;
    priority_queue <pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > minHeap;

    key[0] = 0;
    int ans = 0;

    minHeap.push({ 0, 0 });
    int i = 0;

    while (!minHeap.empty()) {
        int currNode = minHeap.top().second;
        int currKey = minHeap.top().first;
        ans += currKey;
        //cout<<"For Itr :"<<i<<" ans:"<<ans<<" Curr Node:"<<currNode<<endl;
        mst[currNode] = true;
        minHeap.pop();
        for (auto it : adj[currNode]) {
            int nextNode = it[0];
            int nextKey = it[1];
            if (!mst[nextNode] && nextKey < key[nextNode]) {
                parent[nextNode] = currNode;
                key[nextNode] = nextKey;
                minHeap.push({ nextKey, nextNode });
            }
        }
        i++;
    }
    int sum = 0;

    for (int i = 1; i <= V; i++) {
        if (key[i] != INT_MAX) sum += key[i];
    }
    return sum;
}
