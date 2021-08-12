//https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
int maxLen(int A[], int n){
	if (n == 0) return 0;
	unordered_map<int, int> umap;
	int cnt = 0, maximum = 0, i = 0, sum = 0;

	while (i < n) {
		sum += A[i];
		cnt++;
		if (sum == 0)
			maximum = max(maximum, cnt);
		if (umap.find(sum) != umap.end()) {
			maximum = max(maximum, i - umap[sum]);
			i++;
			continue;
		}

		umap[sum] = i;
		i++;

	}
	return maximum;
}
