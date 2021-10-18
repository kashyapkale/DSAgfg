//https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1
void DFS(int node, vector<int> adj[], stack<int> &s, vector<bool> &visited, bool stepOne){
    visited[node] = 1;
    for (auto it:adj[node]) {
        if (!visited[it]) {
            DFS(it, adj, s, visited, stepOne);
        }
    }

    if (stepOne)
        s.push(node);
}


int kosaraju(int V, vector<int> adj[]){
    //topo sort
    stack<int> s;
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            DFS(i, adj, s, visited, true);
        }
    }

    //Get Transpose
    vector<int> transpose[V];

    for (int i = 0; i < V; i++) {
        for (auto it:adj[i]) {
            transpose[it].push_back(i);
        }
        visited[i] = false;
    }
    
    

    //DFS on Stack
    int ans = 0;

    while (!s.empty()) {
        if (!visited[s.top()]) {
            ans++;
            DFS(s.top(), transpose, s, visited, false);
        }
        s.pop();
    }
    return ans;
}
