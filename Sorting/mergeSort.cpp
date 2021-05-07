void merge(int arr[], int l, int m, int r)
{
	int arr1[r + 1];
	int i = l, j = m + 1;
	int k = 0;
	//cout<<"Entering Merge Functiom"<<endl;
	//cout<<"L :"<<arr[l]<<" R :"<<arr[r]<<endl;
	while ((i < m + 1) && (j < r + 1)) {
		if (arr[i] < arr[j]) {
			arr1[k] = arr[i];
			i++;
		}
		else {
			arr1[k] = arr[j];
			j++;
		}

		k++;
	}

	while (i < m + 1) {
		arr1[k] = arr[i];
		i++;
		k++;
	}

	while (j < r + 1) {
		arr1[k] = arr[j];
		j++;
		k++;
	}
	k = 0;
	//cout<<"Working till here"<<endl;
	for (int q = l; q <= r; q++) {
		arr[q] = arr1[k];
		//cout<<arr[q]<<" ";
		k++;
	}

	//cout<<endl;
}

void mergeSort(int arr[], int l, int r)
{
	if (l >= r)
		return;

	int mid = (l + r) / 2;
	//cout<<"FirstHalf"<<endl;
	mergeSort(arr, l, mid);
	//cout<<"SecondHalf"<<endl;
	mergeSort(arr, mid + 1, r);
	merge(arr, l, mid, r);
}
