//https://practice.geeksforgeeks.org/problems/frequency-of-array-elements-1587115620/1
void frequencycount(vector<int>& arr, int n)
{
	int mod = n ;
	for (int i = 0; i < n; i++) {
		arr[i] = arr[i] - 1;
		//cout<<i<<" "<<index<<" "<<arr[index]<<endl;
	}
	
	for (int i = 0; i < n; i++){
	    int index = arr[i];
        arr[index%mod] += mod;
    }

	for (int i = 0; i < n; i++)
		arr[i] = arr[i] / mod;
}
