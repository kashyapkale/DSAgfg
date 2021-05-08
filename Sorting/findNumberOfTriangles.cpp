//https://practice.geeksforgeeks.org/problems/count-possible-triangles-1587115620/1
int findNumberOfTriangles(int arr[], int n) {
	sort(arr, arr + n);
	int ans = 0;
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			int k = n - 1;
			int diff = arr[i] + arr[j];
			while (arr[k] >= diff && k > j)
				k--;
			/*if(k==j)
			    break;*/
			ans += k - j;
		}
	}

	return ans;
}
