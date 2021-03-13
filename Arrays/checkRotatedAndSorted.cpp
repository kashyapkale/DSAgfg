//https://practice.geeksforgeeks.org/problems/check-if-array-is-sorted-and-rotated-clockwise-1587115620/1
int findMax(int arr[], int size) {
	int maximum = INT_MIN;
	int index;

	for (int i = 0; i < size; i++) {
		if (arr[i] > maximum) {
			maximum = arr[i];
			index = i;
		}

	}
	return index;

}


bool increasing(int arr[], int size, int p) {
	if (p != size - 1 && p != 0)
		return ((arr[p - 1] >= arr[0]) && (arr[p + 1] <= arr[0]));

	else if (p == 0)
		return (arr[p + 1] < arr[0]);

	else
		return (arr[p - 1] > arr[0]);
}


bool checkRotatedAndSorted(int arr[], int n) {

	int maxIndex = findMax(arr, n);

	bool flag = true;
	bool flag1;

	if (increasing(arr, n, maxIndex)) {
		//cout<<"Increasing"<<" and MaxIndex is "<<maxIndex<<endl;
		if (maxIndex != n - 1) {
			for (int i = maxIndex + 1; i < n - 1; i++) {
				if (arr[i] > arr[i + 1])
					flag = false;
			}
		}


		if (maxIndex != 0) {
			for (int i = 0; i < maxIndex - 1; i++) {
				if (arr[i] > arr[i + 1])
					flag = false;
			}
		}

		flag1 = (arr[n - 1] < arr[0]);
	}

	else {
		//cout<<"Decreasing"<<" and MaxIndex is "<<maxIndex<<endl;
		if (maxIndex != n - 1) {
			for (int i = maxIndex + 1; i < n - 1; i++) {
				if (arr[i] < arr[i + 1])
					flag = false;
			}
		}


		if (maxIndex != 0) {
			for (int i = 0; i < maxIndex - 1; i++) {
				if (arr[i] < arr[i + 1])
					flag = false;
			}
		}

		flag1 = (arr[n - 1] > arr[0]);
	}
	return (flag & flag1);
}
