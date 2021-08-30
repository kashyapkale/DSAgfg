//https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1/?track=DSASP-Matrix&batchId=274#
//One of the most complex solutions to IMPLEMENT , Logic is easy though
void spiralTraversalUtil(vector<int> &ans, int firstRow, int firstColumn, vector<vector<int> > &matrix, int r, int c){
    if (r <= 0 || c <= 0)
        return;

    int i = firstRow;
    int j = firstColumn;
    int lastCol = firstColumn + c - 1;
    int lastRow = firstRow + r - 1;


    for (; j <= lastCol; j++) {
        if (matrix[i][j] != -1)
            ans.push_back(matrix[i][j]);
        matrix[i][j] = -1;
    }
    j--;
    i++;


    for (; i <= lastRow; i++) {
        if (matrix[i][j] != -1)
            ans.push_back(matrix[i][j]);
        matrix[i][j] = -1;
    }
    j--;
    i--;

    for (; j >= firstColumn; j--) {
        if (matrix[i][j] != -1)
            ans.push_back(matrix[i][j]);
        matrix[i][j] = -1;
    }
    j++;
    i--;

    for (; i >= firstRow + 1; i--) {
        if (matrix[i][j] != -1)
            ans.push_back(matrix[i][j]);
        matrix[i][j] = -1;
    }
    i++;
    j++;

    spiralTraversalUtil(ans, i, j, matrix, r - 2, c - 2);

}



vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c){
    vector<int> ans;

    spiralTraversalUtil(ans, 0, 0, matrix, r, c);
    return ans;
}
