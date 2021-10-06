//bfs traversal of a graph

//For graphs with only one component
vector <int> bfsOfGraph(int N, vector<int> g[]) {
	queue<int> q;
	//vector<bool> visited(N+1, false);
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



//For graphs with multiple components
vector <int> bfsOfGraph(int N, vector<int> g[]) {
	bool *visited = new bool[N + 1]{ false };
	vector<int> ans;

	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			queue<int> q;
			q.push(i);
			while (!q.empty()) {
				for (auto node: g[q.front()]) {
					if (!visited[node]) {
						q.push(node);
						visited[node] = true;
					}
				}
				ans.push_back(q.front());
				q.pop();
			}
		}
	}

	return ans;

}
