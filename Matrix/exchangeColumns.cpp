//https://practice.geeksforgeeks.org/problems/exchange-matrix-columns-1587115620/0/?track=DSASP-Matrix&batchId=274
void exchangeColumns(vector<vector<int> > &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n; i++) 
		      swap(matrix[i][0], matrix[i][m-1]);
	
    }
