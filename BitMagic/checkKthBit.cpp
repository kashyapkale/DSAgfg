//https://practice.geeksforgeeks.org/problems/check-whether-k-th-bit-is-set-or-not-1587115620/0
bool checkKthBit(int n, int k){
    return ((n>>k) & 1)?true:false;   
}
