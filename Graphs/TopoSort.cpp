//https://practice.geeksforgeeks.org/problems/topological-sort/1
//Topological Sort using DFS
void DFS(int node, vector<int> adj[], stack<int> &s, vector<bool> &visited){
	visited[node] = 1;
	for (auto it:adj[node]) {
		if (!visited[it]) {
			DFS(it, adj, s, visited);
		}
	}
	s.push(node);
}


vector<int> topoSort(int V, vector<int> adj[]){
	stack<int> s;
	vector<bool> visited(V, false);

	for (int i = 0; i < V; i++) {
		if (!visited[i]) {
			DFS(i, adj, s, visited);
		}
	}
	vector<int> ans;

	while (!s.empty()) {
		ans.push_back(s.top());
		s.pop();
	}

	return ans;
}
