//https://practice.geeksforgeeks.org/problems/rearrange-an-array-with-o1-extra-space3142/0
void arrange(long long arr[], int n) {
	int mod = n;
	for (int i = 0; i < n; i++)
		arr[i] += (arr[arr[i]] % mod) * mod;
	for (int i = 0; i < n; i++)
		arr[i] = arr[i] / mod;
}
