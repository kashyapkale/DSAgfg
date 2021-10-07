//https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1/
//Used DFS , Works on Leetcode, Gives Segmentation Fault on Gfg
void DFS(int i, int j, int N, int M, vector<vector<bool> > &visited, vector<vector<char> >& grid){
        visited[i][j] = true;
        int xDir[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
        int yDir[] = { 1, 1, 1, 0, -1, -1, -1, 0 };

        for (int k = 0; k < 8; k++) {
                int row = i + xDir[k];
                int col = j + yDir[k];
                if (row >= 0 && row < N && col >= 0 && col < M && grid[row][col] == '1' && !visited[row][col])
                        DFS(row, col, N, M, visited, grid);
        }
}

int numIslands(vector<vector<char> >& grid) {
        int row = grid.size();

        if (row < 0)
                return 0;
        int col = grid[0].size();
        vector<vector<bool> > visited;
        int ans = 0;

        for (int i = 0; i < row; i++) {
                vector<bool> temp;
                for (int j = 0; j < col; j++)
                        temp.push_back(false);
                visited.push_back(temp);
        }

        for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                        if (grid[i][j] == '1' && !visited[i][j]) {
                                ans++;
                                DFS(i, j, row, col, visited, grid);
                        }
                }
        }
        return ans;

}
