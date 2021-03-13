//https://practice.geeksforgeeks.org/problems/max-circular-subarray-sum-1587115620/1

int minSum(int arr[], int n) {
	for (int i = 0; i < n; i++)
		arr[i] *= -1;

	int max_sum = INT_MIN;
	int sum = 0;

	for (int i = 0; i < n; i++) {
		sum += arr[i];
		max_sum = max(sum, max_sum);

		if (sum < 0)
			sum = 0;
	}

	for (int i = 0; i < n; i++)
		arr[i] *= -1;

	return max_sum * -1;
}


int Kadanes(int arr[], int n) {

	int max_sum = INT_MIN;
	int sum = 0;

	for (int i = 0; i < n; i++) {
		sum += arr[i];
		max_sum = max(sum, max_sum);

		if (sum < 0)
			sum = 0;
	}


	return max_sum ;
}


int circularSubarraySum(int arr[], int n) {

	bool flag = false;
	bool flag2 = true;
	int sum = 0, maximum = INT_MIN;

	if (n == 1)
		return arr[0];

	for (int i = 0; i < n; i++) {
		if (arr[i] < 0)
			flag = true;

		if (arr[i] > 0)
			flag2 = false;
		maximum = max(arr[i], maximum);
		sum += arr[i];
	}


	if (flag2)
		return maximum;

	if (flag)
		return max(Kadanes(arr, n), (sum - minSum(arr, n)));



	return sum;

}
