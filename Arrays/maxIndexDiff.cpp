https://practice.geeksforgeeks.org/problems/maximum-index-1587115620/1
int maxIndexDiff(int arr[], int n)
{
	int preArr[n];
	int i = 0, j = n - 1;
	while (i < n) {
		if (i != 0 && arr[i] < arr[i - 1])
			j = n - 1;

		if (arr[i] <= arr[j]) {
			preArr[i] = j;
			i++;
			continue;
		}


		while (j >= 0 && arr[i] > arr[j])
			j--;

		if (j >= 0)
			preArr[i] = j;
		else
			preArr[i] = i;

		i++;
	}

	int maximum = INT_MIN;
	for (int k = 0; k < n; k++) {
		preArr[k] = preArr[k] - k;
		maximum = max(maximum, preArr[k]);
	}

	return maximum;

}
