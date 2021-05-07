//https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
long long int merge(long long int arr[], long long int l, long long int m, long long int r)
{
	long long int arr1[r - l + 1];
	long long int i = l, j = m + 1;
	long long int k = 0;
	long long int invert = 0;
	//cnt++;
	//cout<<"Entering Merge Functiom"<<endl;
	//cout<<"L :"<<arr[l]<<" R :"<<arr[r]<<endl;
	while ((i < m + 1) && (j < r + 1)) {
		if (arr[i] <= arr[j]) {
			arr1[k] = arr[i];
			i++;
		}
		else {
			invert += (m + 1 - i);
			arr1[k] = arr[j];
			j++;
		}

		k++;
	}

	while (i < m + 1) {
		//cnt++;
		arr1[k] = arr[i];
		i++;
		k++;
	}

	while (j < r + 1) {
		//cnt++;
		arr1[k] = arr[j];
		j++;
		k++;
	}
	k = 0;

	for (long long int q = l; q <= r; q++) {
		arr[q] = arr1[k];

		k++;
	}
	return invert;

}

long long int mergeSort(long long int arr[], long long int l, long long int r)
{
	if (l >= r)
		return 0;

	long long int invert = 0;

	long long int mid = (l + r) / 2;
	//cout<<"FirstHalf"<<endl;
	invert += mergeSort(arr, l, mid);
	//cout<<"SecondHalf"<<endl;
	invert += mergeSort(arr, mid + 1, r);
	invert += merge(arr, l, mid, r);
	return invert;
}

long long int inversionCount(long long arr[], long long N)
{

	return mergeSort(arr, 0, N - 1);

}
