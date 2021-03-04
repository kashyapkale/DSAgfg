//https://practice.geeksforgeeks.org/problems/longest-subarray-of-evens-and-odds/1
//Exec Time : 0.01 sec
int maxEvenOdd(int arr[], int n)
{
	int mod = 10e3 + 7;
	arr[0] += (1 % mod) * mod;

	for (int i = 1; i < n; i++) {
		int x = 1;
		if ((arr[i] + (arr[i - 1] % mod)) % 2 != 0)
			x = (arr[i - 1] / mod) + 1;

		arr[i] += (x % mod) * mod;

	}



	int maximum = INT_MIN;
	for (int i = 0; i < n; i++) {
		arr[i] = arr[i] / mod;
		maximum = max(maximum, arr[i]);
	}



	return maximum;
}
