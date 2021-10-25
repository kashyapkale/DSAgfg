//https://practice.geeksforgeeks.org/problems/find-whether-path-exist5238/1
bool is_Possible(vector<vector<int> >& grid){
    int row = grid.size();
    int col = grid[0].size();
    vector<vector<bool> > visited( row + 1, vector<bool> (col + 1, false));

    //sr-sourcee Row , sc-Source Column , er-End Row , ec-End Column
    int sr, sc, er, ec;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (grid[i][j] == 1) {
                sr = i;
                sc = j;
            }
            else if (grid[i][j] == 2) {
                er = i;
                ec = j;
            }
        }
    }

    int xDir[] = { 0, 1, 0, -1 };
    int yDir[] = { -1, 0, 1, 0 };
    queue<pair<int, int> > q;
    visited[sr][sc] = true;
    q.push(make_pair(sr, sc));
    while (!q.empty()) {
        int currRow = q.front().first;
        int currCol = q.front().second;
        
        if(grid[currRow][currCol]==2)
            return true;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nextRow = xDir[i] + currRow;
            int nextCol = yDir[i] + currCol;
            if (nextRow >= 0 && nextRow < row && nextCol >= 0 && nextCol < col && !visited[nextRow][nextCol] && grid[nextRow][nextCol] != 0) {
                visited[nextRow][nextCol] = true;
                q.push(make_pair(nextRow, nextCol));
            }
        }
    }

    if (visited[er][ec])
        return true;

    return false;
}
