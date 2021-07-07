//https://practice.geeksforgeeks.org/problems/path-in-matrix3805/1#
int maximumPath(int N, vector<vector<int>> arr)
{
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (j > 0 && j < N - 1)
				arr[i][j] += max(arr[i - 1][j], max(arr[i - 1][j - 1], arr[i - 1][j + 1]));

			else if (j < N-1)
				arr[i][j] += max(arr[i - 1][j],  arr[i - 1][j + 1]);

			else if(j > 0)
				arr[i][j] += max(arr[i - 1][j],  arr[i - 1][j - 1]);
		}
	}

	int maximum = 0;
	for (int k = 0; k < N ; k++)
		maximum = max(maximum, arr[N - 1][k]);

	return maximum;
}
