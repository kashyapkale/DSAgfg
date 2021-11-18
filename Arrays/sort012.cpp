//https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1
void sort012(int a[], int n)
    {
        int high=n-1,low=0,mid=0;
		while(high>=mid){
			if(a[mid] == 0){
				swap(a[low],a[mid]);
				low++;
				mid++;
			}
			else if(a[mid] == 2){
				swap(a[high],a[mid]);
				high--;
			}
			else
				mid++;
		}
    }
