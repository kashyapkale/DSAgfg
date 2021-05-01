//https://practice.geeksforgeeks.org/problems/quick-sort/1
int partition (int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = low - 1;

	for (int j = low; j < high; j++) {
		if (arr[j] <= pivot) {


			i++;


			swap(arr[i], arr[j]);
		}
	}

	swap(arr[high], arr[i + 1]);
	return i + 1;
}


void quickSort(int arr[], int low, int high)
{
	if (low < high) {
		int pivot = partition(arr, low, high);
		quickSort(arr, low, pivot - 1);
		quickSort(arr, pivot + 1, high);
	}
}
