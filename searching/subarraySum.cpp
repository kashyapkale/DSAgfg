https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1
vector<int> subarraySum(int arr[], int n, int s) {
	std::vector<int> ans{ -1, -1};
	int j = 0, sum = 0;

	for (int i = 0; i < n; i++ ) {
		sum += arr[i];

		while (sum > s) {
			sum -= arr[j];
			j++;
		}

		if (sum == s) {
			ans[0] = j + 1;
			ans[1] = i + 1;
			return ans;
		}
	}

	ans.pop_back();
	return ans;
}
