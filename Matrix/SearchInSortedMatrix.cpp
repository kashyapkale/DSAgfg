//https://practice.geeksforgeeks.org/problems/search-in-a-matrix-1587115621/1/?track=DSASP-Matrix&batchId=274
bool search(vector<vector<int> > matrix, int n, int m, int x){
    int i = n - 1;
    int j = 0;

    while (i >= 0 && j < m) {
        if (matrix[i][j] == x)
            return true;

        if (matrix[i][j] < x) {
            j++;
            continue;
        }

        if (matrix[i][j] > x) {
            i--;
            continue;
        }

    }

    return false;
}
