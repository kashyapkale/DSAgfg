//https://practice.geeksforgeeks.org/problems/fibonacci-using-recursion/0
long long fibonacci(int n)
{
    if(n==2 || n==1)
        return 1;
        
    return fibonacci(n-1) + fibonacci(n-2);
}
