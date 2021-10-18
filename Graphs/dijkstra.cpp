//https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
//Dijkstra's Algorithm
vector <int> dijkstra(int V, vector<vector<int> > adj[], int S){
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > minHeap;

    minHeap.push({ 0, S });
    vector<int> distanceArr(V + 1, INT_MAX);
    distanceArr[S] = 0;
    while (!minHeap.empty()) {
        int currNode = minHeap.top().second;
        int distance = minHeap.top().first;
        minHeap.pop();
        if(distanceArr[currNode] < distance) continue;
        for (auto it:adj[currNode]) {
            int nextNode = it[0];
            int nextDist = it[1];
            if (distanceArr[currNode] + nextDist < distanceArr[nextNode]) {
                distanceArr[nextNode] = distanceArr[currNode] + nextDist;
                minHeap.push({ distanceArr[currNode] + nextDist, nextNode });
            }
        }
    }

    return distanceArr;

}
