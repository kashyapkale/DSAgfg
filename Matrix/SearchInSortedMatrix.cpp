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

//LeetCode Variation
int matSearch(vector <vector <int> > &mat, int N, int M, int X){
	int high = (N * M) - 1;
	int low = 0;

	while (low <= high) {
		int mid = low + ((high-low) / 2);
		int row = mid / M;
		int col = mid % M;
		if (mat[row][col] == X)
			return 1;

		if (mat[row][col] < X)
			low = mid + 1;

		if (mat[row][col] > X)
			high = mid - 1;
	}

	return 0;
}
