//https://practice.geeksforgeeks.org/problems/number-is-sparse-or-not-1587115620/0
bool isSparse(int n){
    
    int mem = n & 1;
    n=n>>1;
    while(n!=0){
        if((n&1) & mem)
            return false;
        mem = n&1;
        n = n>>1;
    }
    return true;
    
}
