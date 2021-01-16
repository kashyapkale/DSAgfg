//https://practice.geeksforgeeks.org/problems/bit-difference-1587115620/0
int countBitsFlip(int a, int b){
    int cnt = 0;
    while(a!=0 || b!=0){
        if((a&1) ^ (b&1) == 1)
            cnt++;
        a=a>>1;
        b=b>>1;
    }
    return cnt;
    
}
