https://practice.geeksforgeeks.org/problems/lucky-numbers2911/1
bool isLucky(int n, int counter) {
	if (counter > n)
		return true;

	if (n % counter == 0)
		return false;
	int pos = counter;
	return isLucky(n - (n / pos), pos + 1);
}
