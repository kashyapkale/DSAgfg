//https://practice.geeksforgeeks.org/problems/tower-of-hanoi-1587115621/1
long long toh(int N, int from, int to, int aux) {
	if (N == 0)
		return 0;

	long long ans = toh(N - 1, from, aux, to);
	cout << "move disk " << N << " from rod " << from << " to rod " << to << endl;
	ans += toh(N - 1, aux, to, from);
	return ans+1;
}
