//bfs traversal of a graph
vector <int> bfsOfGraph(int N, vector<int> g[]) {
	queue<int> q;
// vector<bool> visited(N+1, false);
	bool *visited = new bool[N + 1] {false};
	vector<int> ans;

	q.push(0);
	while (!q.empty()) {
		for (auto node : g[q.front()]) {
			if (! visited[node]) {
				q.push(node);
				visited[node] = true;
			}
		}
		ans.push_back(q.front());
		q.pop();
	}
	return ans;
}
