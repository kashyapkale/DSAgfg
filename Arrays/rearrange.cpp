//https://practice.geeksforgeeks.org/problems/-rearrange-array-alternately-1587115620/0
void rearrange(long long *arr, int n)
	{
		int mod = arr[n - 1] + 1;
		int min_index = 0, max_index = n - 1;

		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) {
				arr[i] += (arr[max_index] % mod) * mod;
				max_index--;
			}
			else {
				arr[i] += (arr[min_index] % mod) * mod;
				min_index++;
			}
		}

		for (int i = 0; i < n; i++)
			arr[i] = arr[i] / mod;

	}
