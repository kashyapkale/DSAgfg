//https://practice.geeksforgeeks.org/problems/n-queen-problem0315/1#
//Difficult Problem
bool isSafe(int row, int col, vector<string> &board, int n){
    int row_ = row;
    int col_ = col;

    while (row >= 0 && col >= 0) {
        if (board[row][col] == 'Q')
            return false;
        row--;
        col--;
    }

    col = col_;
    row = row_;

    while (col >= 0) {
        if (board[row][col] == 'Q')
            return false;
        col--;
    }

    col = col_;
    row = row_;

    while (col >= 0 && row < n) {
        if (board[row][col] == 'Q')
            return false;
        col--;
        row++;
    }

    return true;
}


void solve(int col, vector<string> &board, vector<vector<string> > &ans, int n){
    if (col == n) {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 'Q';
            solve(col + 1, board, ans, n);
            board[row][col] = '-';
        }
    }
}

vector<vector<int> > nQueen(int n) {
    vector<string> board(n);
    vector<vector<string> > ans;
    string s(n, '-');

    for (int i = 0; i < n; i++)
        board[i] = s;

    solve(0, board, ans, n);

    vector<vector<int> > FinalAns;

    for (auto it:ans) {
        vector<int> temp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (it[i][j] == 'Q')
                    temp.push_back(j + 1);
            }
        }
        FinalAns.push_back(temp);
    }
    sort(FinalAns.begin(), FinalAns.end());
    return FinalAns;
}
