//https://practice.geeksforgeeks.org/problems/insertion-sort/1
void insertionSort(int arr[], int n)
{
	for (int i = 1; i < n; i++ ) {
		int temp = arr[i];
		int j = i;
		while (arr[j - 1] > temp && j > 0) {
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = temp;
	}
}
