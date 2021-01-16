//https://practice.geeksforgeeks.org/problems/count-total-set-bits-1587115620/0
int largestPowerof2(int N){
    int x = 0;
    
    while((1<<x) <= N){
        x++;
    }
    
    return x-1;
}


int countSetBits(int n)
{
    if(n==0)
        return 0;
    int powOfTwo = largestPowerof2(n);
    
    int ans = ((1<<(powOfTwo-1)) * powOfTwo) + (n - (1<<powOfTwo) +1) + countSetBits(n - (1<<powOfTwo)) ;  
    return ans;
}
