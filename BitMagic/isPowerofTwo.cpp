//https://practice.geeksforgeeks.org/problems/power-of-2-1587115620/0
bool isPowerofTwo(long long n){
    
    return __builtin_popcountll(n)==1 ;
    
}
