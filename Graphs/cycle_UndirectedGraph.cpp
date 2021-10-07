//https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/0
//Cycle in an Undirected Graph
bool cycleDFS(int node, int parent, vector<bool> &visited, vector<int> adj[]){
        visited[node] = true;
        for (auto it:adj[node]) {
            if(it != parent){
                if (visited[it])
                        return true;
                else
                        if(cycleDFS(it, node, visited, adj))
                                return true;
        
            }    
            
        }

        return false;

}



bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V+1, false);

        for (int i = 0; i < V; i++) {
                visited[i] = true;
                for (auto it:adj[i])
                        if (!visited[it] && cycleDFS(it, i, visited, adj))
                                return true;

        }

        return false;
}
