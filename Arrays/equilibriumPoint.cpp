//https://practice.geeksforgeeks.org/problems/equilibrium-point-1587115620/0
int equilibriumPoint(long long a[], int n) {
	int i = 0, j = i + 1, size = n;
	int prevSum = 0;
	int arr_sum = accumulate(a, a + n, 0);

	if (n == 1)
		return 1;

	while (size--) {
		prevSum += a[i];
		bool check = ((arr_sum - a[j] - prevSum) == prevSum);

		if (check)
			return j + 1;

		i++;
		j++;

		if (j == n)
			break;
	}

	return -1;

}
