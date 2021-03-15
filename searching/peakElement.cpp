//https://practice.geeksforgeeks.org/problems/peak-element/1
int peakElement(int arr[], int n)
{
	if (arr[n - 1] > arr[n - 2])
		return n - 1;

	if (arr[0] > arr[1])
		return 0;

	int low = 0, high = n - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if ((arr[mid] > arr[mid + 1]) && (arr[mid] > arr[mid - 1]))
			return mid;

		low = mid + 1;
	}

	return -1;


}
