//https://practice.geeksforgeeks.org/problems/minimum-swaps/1
int minSwaps(vector<int>&nums){
	vector<pair<int, int> > nums2;
	int ans = 0;

	for (int i = 0; i < nums.size(); i++)
		nums2.push_back(make_pair(nums[i], i));
	int n = nums2.size();
	vector<bool> visited(n, false);

	sort(nums2.begin(), nums2.end());
	for (int i = 0; i < n; i++) {
		if (visited[i] || (nums2[i].second == i))
			continue;
		int cycle = 0;
		int j = i;
		while (!visited[j]) {
			visited[j] = true;
			j = nums2[j].second;
			cycle++;
		}

		if (cycle > 0)
			ans += cycle - 1;

	}

	return ans;

}
