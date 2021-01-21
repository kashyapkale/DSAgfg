//https://practice.geeksforgeeks.org/problems/minimum-absloute-difference-between-adjacent-elements-in-a-circular-array-1587115620/1
int minAdjDiff(int arr[], int n) {
	int minimum = INT_MAX;
	for (int i = 0; i < n; i++) {
		if (i != n - 1) {
			minimum = min(minimum, abs((arr[i] - arr[i + 1])));
		}
		else {
			minimum = min(minimum, abs((arr[i] - arr[0])));
		}
	}
	return minimum;
}
