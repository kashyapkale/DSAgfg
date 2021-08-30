//https://practice.geeksforgeeks.org/problems/reversing-the-columns-of-a-matrix-1587115621/1/?track=DSASP-Matrix&batchId=274
void reverseCol(vector<vector<int> > &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n; i++) {
		int p = 0;
		int q = m - 1;
		while (p <= q) {
			swap(matrix[i][p], matrix[i][q]);
			p++;
			q--;
		}
	}
}
