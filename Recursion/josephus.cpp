//https://practice.geeksforgeeks.org/problems/josephus-problem/0
int josephusDriver(int n, int k)
{
	if(n==1)
		return 0;

	return (josephusDriver(n-1,k)+k)%n;
}

int josephus(int n, int k)
{
	return josephusDriver(n,k) + 1;
}
