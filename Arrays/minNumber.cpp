//https://practice.geeksforgeeks.org/problems/minimum-number-in-a-sorted-rotated-array-1587115620/1
int minNumber(int arr[], int low, int high)
{

	if (arr[low] < arr[high])
		return arr[low];

	int mid = high + low ;
	if (arr[mid] < arr[mid - 1])
		return arr[mid];

	if (arr[mid] > arr[0])
		return minNumber(arr, mid + 1, high);

	return minNumber(arr, low, mid - 1);

}
