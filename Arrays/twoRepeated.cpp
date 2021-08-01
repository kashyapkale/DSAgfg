//https://practice.geeksforgeeks.org/problems/two-repeated-elements-1587115621/0
pair<int, int> twoRepeated (int arr[], int n)
{
	int mod = n + 1;
	vector<int> ans;


	for (int i = 0; i < n + 2; i++) {
		if (arr[abs(arr[i]) - 1] < 0)
			ans.push_back(abs(arr[i]));
		arr[abs(arr[i]) - 1] *= -1;
	}

	return make_pair(ans[0], ans[1]);
}
