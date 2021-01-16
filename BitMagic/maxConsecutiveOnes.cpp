//https://practice.geeksforgeeks.org/problems/longest-consecutive-1s-1587115620/0
int maxConsecutiveOnes(int x)
{
    int sum = 0; int maximum = 0;
    while(x!=0){
        if((x&1) == 1)
            sum++;
        else{
            maximum = max(maximum,sum);
            sum = 0;
        }
        
        x = x>>1;
    }
    return max(maximum,sum);
}
