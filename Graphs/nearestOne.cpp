//https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1#
//Distance of Nearest Cell Having One -> Done Using BFS
typedef pair<int, int> cell;

bool isValid(int row, int col, int maxRow, int maxCol){
	return row >= 0 && col >= 0 && col < maxCol && row < maxRow;
}

vector<vector<int> >nearest(vector<vector<int> >grid){
	int row = grid.size();
	int col = grid[0].size();
	vector<vector<int> > ans(row, vector<int>(col, 0));
	queue<cell> dfsQ;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (grid[i][j] == 1) {
				dfsQ.push(make_pair(i, j));
			}
			else{
				ans[i][j] = -1;
			}
		}
	}

	int xDir[] = { 0, 1, 0, -1 };
	int yDir[] = { 1, 0, -1, 0 };

	while (!dfsQ.empty()) {
		cell temp = dfsQ.front();
		dfsQ.pop();

		for (int k = 0; k < 4; k++) {
			int nextX = temp.first + xDir[k];
			int nextY = temp.second + yDir[k];
			if (isValid(nextX, nextY, row, col) && ans[nextX][nextY] == -1) {
				ans[nextX][nextY] = ans[temp.first][temp.second] + 1;
				dfsQ.push(make_pair(nextX, nextY));
			}
		}
	}

	return ans;
}
