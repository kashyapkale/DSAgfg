//https://practice.geeksforgeeks.org/problems/gray-to-binary-equivalent-1587115620/0
int grayToBinary(int n)
{
    int inv = 0; 
  
    // Taking xor until n becomes zero 
    for (; n; n = n >> 1) 
        inv ^= n; 
  
    return inv;  
}
