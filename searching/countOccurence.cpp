//https://practice.geeksforgeeks.org/problems/count-element-occurences/1
int countOccurence(int arr[], int n, int k) {
	unordered_map<int, int> umap;
	for (int i = 0; i < n; i++)
		umap[arr[i]]++;

	int m = (n / k) , cnt = 0;

	for (auto it : umap) {
		if (it.second > m)
			cnt++;
	}

	return cnt;
}
