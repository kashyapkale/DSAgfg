//https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1#
bool isSafe(int node, bool graph[101][101], int color[], int N, int color_Num){
	for (int k = 0; k < N; k++) {
		if (node != k && graph[k][node] == 1 && color[k] == color_Num)
			return false;
	}

	return true;
}

bool solve(int node, bool graph[101][101], int color[], int m, int N){
	if (node == N)
		return true;

	for (int i = 1; i <= m; i++) {
		if (isSafe(node, graph, color, N, i)) {
			color[node] = i;
			if (solve(node + 1, graph, color, m, N))
				return true;
			color[node] = 0;
		}
	}

	return false;
}

bool graphColoring(bool graph[101][101], int m, int N){
	int color[N] = { 0 };

	return solve(0, graph, color, m, N);
}
