//https://practice.geeksforgeeks.org/problems/find-first-set-bit-1587115620/1
unsigned int getFirstSetBit(int n){
    if(n!=0){
        int cnt = 0;
        while(true){
            if((n&1) == 1){
                cnt++;
                return cnt;
            }
            cnt++;
            n = n>>1;
        }
        return cnt-1;
    }
    
    return 0;
}
