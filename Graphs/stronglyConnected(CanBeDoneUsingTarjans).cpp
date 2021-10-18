//https://practice.geeksforgeeks.org/problems/strongly-connected-component-tarjanss-algo-1587115621/0
//Strongly Connected Components Elements
//Can Be done using Tarjans Algorithm
//I just did slight modification to Kosarajus Algorithm

void DFS(int node, vector<int> adj[], stack<int> &s, vector<bool> &visited, bool stepOne, vector<int> &v){
    visited[node] = 1;
    if (!stepOne)
        v.push_back(node);

    for (auto it:adj[node]) {
        if (!visited[it]) {
            DFS(it, adj, s, visited, stepOne,v);
        }
    }

    if (stepOne)
        s.push(node);

}

vector<vector<int> > stronglyConnected(int V, vector<int> adj[]){
    //topo sort
    stack<int> s;
    vector<bool> visited(V, false);
    vector<int> dummy;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            DFS(i, adj, s, visited, true, dummy);
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
    //int ans = 0;
    vector<vector<int> > ans;

    while (!s.empty()) {
        vector<int> temp;
        if (!visited[s.top()]) {
            DFS(s.top(), transpose, s, visited, false,temp);
        }
        if(temp.size()>0){
            sort(temp.begin(),temp.end());
            ans.push_back(temp);}
        s.pop();
    }
    sort(ans.begin(),ans.end());
    return ans;
}
