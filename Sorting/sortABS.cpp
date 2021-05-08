//https://practice.geeksforgeeks.org/problems/sort-by-absolute-difference-1587115621/0
void merge(int arr[], int B[], int l, int m, int r)
{
	int arr1[r + 1];
	int arr2[r + 1];
	int i = l, j = m + 1;
	int k = 0;
	//cout<<"Entering Merge Functiom"<<endl;
	//cout<<"L :"<<arr[l]<<" R :"<<arr[r]<<endl;
	while ((i < m + 1) && (j < r + 1)) {
		if (arr[i] <= arr[j]) {
			arr1[k] = arr[i];
			arr2[k] = B[i];
			i++;
		}
		else {
			arr1[k] = arr[j];
			arr2[k] = B[j];
			j++;
		}

		k++;
	}

	while (i < m + 1) {
		arr1[k] = arr[i];
		arr2[k] = B[i];
		i++;
		k++;
	}

	while (j < r + 1) {
		arr1[k] = arr[j];
		arr2[k] = B[j];
		j++;
		k++;
	}
	k = 0;
	//cout<<"Working till here"<<endl;
	for (int q = l; q <= r; q++) {
		arr[q] = arr1[k];
		B[q] = arr2[k];
		//cout<<arr[q]<<" ";
		k++;
	}

	//cout<<endl;
}

public:
void mergeSort(int arr[], int B[], int l, int r)
{
	if (l >= r)
		return;

	int mid = (l + r) / 2;
	//cout<<"FirstHalf"<<endl;
	mergeSort(arr, B, l, mid);
	//cout<<"SecondHalf"<<endl;
	mergeSort(arr, B, mid + 1, r);
	merge(arr, B, l, mid, r);
}


void sortABS(int A[], int N, int k)
{
	int B[N];
	for (int i = 0; i < N; i++)
		B[i] = abs(A[i] - k);

	mergeSort(B, A, 0, N - 1);

}
