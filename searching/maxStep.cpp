//https://practice.geeksforgeeks.org/problems/roof-top-1587115621/1
int maxStep(int A[], int N) {
	int maximum = 0;
	int cnt = 0;

	if (N < 2)
		return 0;

	for (int i = 1; i < N; i++) {
		if (A[i] <= A[i - 1])
			cnt = 0;
		else
			cnt++;

		maximum = max(maximum, cnt);
	}

	return maximum;
}
