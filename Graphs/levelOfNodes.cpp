//https://practice.geeksforgeeks.org/problems/level-of-nodes-1587115620/1
//Level of Nodes
int nodeLevel(int V, vector<int> adj[], int X){
	vector<bool> visited(V + 1, false);
	queue<pair<int, int> > q;

	q.push(make_pair(0, 0));
	while (!q.empty()) {
		int curr = q.front().first;
		int level = q.front().second;
		if (curr == X)
			return level;
		visited[curr] = true;
		for (auto it:adj[curr]) {
			if (!visited[it])
				q.push(make_pair(it, level + 1));
		}
		q.pop();
	}

	return -1;
}
