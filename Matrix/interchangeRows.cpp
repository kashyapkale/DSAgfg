//https://practice.geeksforgeeks.org/problems/reversing-the-rows-of-a-matrix-1587115621/1/?track=DSASP-Matrix&batchId=274
void interchangeRows(vector<vector<int> > &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < m; i++) {
		int p = 0;
		int q = n - 1;
		while (p <= q) {
			swap(matrix[p][i], matrix[q][i]);
			p++;
			q--;
		}
	}
    }
