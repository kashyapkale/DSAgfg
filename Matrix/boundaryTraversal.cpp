//https://practice.geeksforgeeks.org/problems/boundary-traversal-of-matrix-1587115620/1/?track=DSASP-Matrix&batchId=274
//Unnecessary Lines in code , because the snippet was taken from already implemented solution.
vector<int> boundaryTraversal(vector<vector<int> > matrix, int r, int c) 
    {
    vector<int> ans;    
    int firstRow = 0;
    int firstColumn = 0;
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
    
    return ans;
    }
