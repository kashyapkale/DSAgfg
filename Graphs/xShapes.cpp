//https://practice.geeksforgeeks.org/problems/x-total-shapes3617/0
//Same as Number of Islands
void DFS(int i, int j, int N, int M, vector<vector<bool> > &visited,vector<vector<char> >& grid){
        visited[i][j] = true;
        int xDir[] = {-1,0,1,0};
        int yDir[] = {0,1,0,-1};

        for (int k = 0; k < 4; k++) {
                int row = i + xDir[k];
                int col = j + yDir[k];
                if (row >= 0 && row < N && col >= 0 && col < M && grid[row][col]=='X' && !visited[row][col])
                        DFS(row, col, N, M, visited,grid);
        }
}

    int xShape(vector<vector<char>>& grid) 
    {
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
                        if (grid[i][j] == 'X' && !visited[i][j]) {
                                ans++;
                                DFS(i, j, row, col, visited,grid);
                        }
                }
        }
        return ans;
    }
