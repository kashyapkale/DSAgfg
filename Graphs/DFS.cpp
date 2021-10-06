//https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/0
//DFS on Graphs using Recursion
void DFS(int node, vector<int> &ans, vector<int> adj[], vector<bool> &visited){
        visited[node] = true;
        ans.push_back(node);
        for (auto it:adj[node]) {
                if (!visited[it])
                        DFS(it, ans, adj, visited);
        }
}




vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        vector<int> ans;

        for (int i = 0; i < V; i++) {
                if (!visited[i])
                        DFS(i, ans, adj, visited);
        }

        return ans;
}
