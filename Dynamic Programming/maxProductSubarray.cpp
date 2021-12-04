//https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1
long long getMax(long long A, long long B, long long C){
	if (A < B) {
		A = B;
	}

	if (A < C) {
		A = C;
	}

	return A;
}

long long getMin(long long A, long long B, long long C){
	if (A > B) {
		A = B;
	}

	if (A > C) {
		A = C;
	}

	return A;
}
long long maxProduct(vector<int> arr, int n) {
	long long currMax = 1;
	long long currMin = 1;
	long long maxProduct = INT_MIN;

	for (int i = 0; i < n; i++) {
		long long temp = currMax;
		currMax = getMax(arr[i], arr[i] * currMax, arr[i] * currMin);
		currMin = getMin(arr[i], arr[i] * temp, arr[i] * currMin);
		maxProduct = getMax(currMax, maxProduct, INT_MIN);

		if (currMax == 0)
			currMax = 1;
		if (currMin == 0)
			currMin = 1;
	}

	return maxProduct;
}
