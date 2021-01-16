//https://practice.geeksforgeeks.org/problems/maximum-and-value-1587115620/1
int checkBit(int pattern, int arr[], int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if ((pattern & arr[i]) == pattern) {
			count++;
		}
	}
	return count;
}

int maxAND(int arr[], int n) {
	int res = 0,cnt;
	for (int b = 31; b >= 0; b--) {
		 cnt = checkBit(res | (1 << b), arr, n);

		if (cnt >= 2)
			res |= (1 << b);
	}
	return res;
}
