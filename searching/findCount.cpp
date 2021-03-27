//https://practice.geeksforgeeks.org/problems/count-only-repeated2047/0
//0.26sec
int findCount(int *arr, int index, int n) {
	int target = arr[index];
	int cnt = 1;
	int front = index + 1;
	int back = index - 1;

	while ((front < n && arr[front] == target) || (back >= 0 && arr[back] == target)) {
		if ((back >= 0) && arr[back] == target) {
			cnt++;
			back--;
		}

		if ((front < n) && arr[front] == target) {
			cnt++;
			front++;
		}

	}

	return cnt;
}


pair<int, int> findRepeating(int *arr, int n) {
	int low = 0, high = n - 1;

	while (low <= high) {
		int mid = (low + high) / 2;
		if (arr[mid] == arr[mid - 1]  || arr[mid] == arr[mid + 1])
			return make_pair(arr[mid], findCount(arr, mid, n));

		if (mid - 1 - low  != arr[mid - 1] - arr[low]) {
			high = mid - 1;
			continue;
		}

		low = mid + 1;

	}

	return make_pair(-1, -1);
}

