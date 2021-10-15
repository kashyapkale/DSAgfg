//https://practice.geeksforgeeks.org/problems/rotten-oranges2536/0
class Orange {
public:
int rowPos;
int colPos;
int currTime;
Orange(int row, int col, int time_){
        rowPos = row;
        colPos = col;
        currTime = time_;
}
};

bool isValid(int row, int col, int maxRow, int maxCol){
        return row >= 0 && col >= 0 && col < maxCol && row < maxRow;
}

int orangesRotting(vector<vector<int> >& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int xDir[] = { 0, 1, 0, -1 };
        int yDir[] = { 1, 0, -1, 0 };
        int ans = -1;
        vector<vector<bool> > visited(row, vector<bool>(col, false));
        int totOrange = 0, cnt = 0;
        queue<Orange> q;

        for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                        if (grid[i][j] == 2) {
                                Orange o(i, j, 0);
                                q.push(o);
                        }
                        if (grid[i][j] != 0) {
                                totOrange++;
                        }
                }
        }

        //cout<<"Working till h"<<endl;
        while (!q.empty()) {
                //int qSize = q.size();
                //cnt+=qSize;
                Orange currO = q.front();
                //visited[currO.rowPos][currO.colPos] = true;
                q.pop();
                int i = currO.rowPos;
                int j = currO.colPos;
                for (int k = 0; k < 4; k++) {
                        int currRow = i + xDir[k];
                        int currCol = j + yDir[k];
                        int currTime = currO.currTime + 1;
                        if (isValid(currRow, currCol, row, col)  && grid[currRow][currCol] == 1) {
                                Orange o(currRow, currCol, currTime);
                                q.push(o);
                                grid[currRow][currCol] = 2;
                                //cout<<currTime<<endl;
                                ans = max(ans, currTime);
                        }
                }
        }

        for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                        if (grid[i][j] == 1)
                                return -1;
                }
        }
        //cout<<cnt<<" "<<totOrange<<" "<<endl;
        return ans;
}
