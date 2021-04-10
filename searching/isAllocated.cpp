//https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/0
bool isAllocated(int T, int arr[], int n, int m) {
	int cnt = 1, sum = 0;

	for (int i = 0; i < n; i++) {
		if (arr[i] > T)
			return false;

		sum += arr[i];

		if (sum > T) {
			sum = arr[i];
			cnt++;
		}

		if (cnt > m)
			return false;
	}

	return true;
}


int findPages(int arr[], int n, int m) {
	int high = 0, low = 0, result = -1;
	for (int i = 0; i < n; i++)
		high += arr[i];

	while (low <= high) {
		int mid = (low + high) / 2;
		if (isAllocated(mid, arr, n, m)) {
			result = mid;
			high = mid - 1;
		}
		else
			low = mid + 1;
	}
	return result;
}
