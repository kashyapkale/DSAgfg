//https://practice.geeksforgeeks.org/problems/rightmost-different-bit-1587115621/1
int posOfRightMostDiffBit(int m, int n)
{
    int cnt = 0;
    while(m!=0 || n!=0){
        if((m&1) ^ (n&1) == 1){
            cnt++;
            return cnt;
        }
        
        cnt++;
        m = m>>1;
        n = n>>1;
    }
    
    return -1;
}
