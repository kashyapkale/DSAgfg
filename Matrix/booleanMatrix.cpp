//https://practice.geeksforgeeks.org/problems/boolean-matrix-problem-1587115620/0/?track=DSASP-Matrix&batchId=274#
void booleanMatrix(vector<vector<int> > &matrix){
	int R = matrix.size();
	int C = matrix[0].size();
	vector<int> row(R, 0);
	vector<int> column(C, 0);

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (matrix[i][j]) {
				row[i] = 1;
				column[j] = 1;
			}
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (row[i] || column[j]) {
				matrix[i][j] = 1;
			}
		}
	}

}
