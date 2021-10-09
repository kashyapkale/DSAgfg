
//https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/0
bool isCyclicUtil(int node, vector<bool> &visited, vector<bool> &dfsVisited, vector<int> adj[]){
    visited[node] = true;
    dfsVisited[node] = true;

    for (auto it:adj[node]) {
        if (!visited[it]) {
            if (isCyclicUtil(it, visited, dfsVisited, adj))
                return true;
        }
        else if (dfsVisited[it])
            return true;
    }
    dfsVisited[node] = false;
    return false;
}



bool isCyclic(int V, vector<int> adj[]) {
    vector<bool> visited(V + 1, false);
    vector<bool> dfsVisited(V + 1, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (isCyclicUtil(i, visited, dfsVisited, adj))
                return true;
        }
    }

    return false;

}

