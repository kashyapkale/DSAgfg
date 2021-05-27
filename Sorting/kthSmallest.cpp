//https://practice.geeksforgeeks.org/problems/kth-smallest-element5545-1587115620/1
int partition (int arr[], int high, int low)
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
  //cout<<"Pivot : "<<i+1<<endl;
  return i + 1;
}



int kthSmallest(int arr[], int n, int k) {
  int low = 0;
  int high = n - 1;
  while (low <= high) {
    int pivot = partition(arr, high, low);
    if (pivot == k - 1)
      return arr[pivot];
    if (pivot > k - 1)
      high = pivot - 1;
    else
      low = pivot + 1;
  }

  return arr[0];
}


//The problem is to find kth smallest element in an unsorted array
//the approach takes O(log(k)) time with no extra space
//answer uses partition algorithm that is used in quick sort
//once partition algorithm is run over an array it returns the
//sorted position of the pivot element , which means
//all elements in the right of pivot element are bigger than pivot
//all elements left to pivot element are smaller than pivot element.
//thus running partition algorithm over pivot element till
//pivot == k - 1 (k-1 because partition algo uses 0 based indexing)
// will give us our solution
