//https://practice.geeksforgeeks.org/problems/gray-to-binary-equivalent-1587115620/0
int grayToBinary(int n)
{
    return n ^ (n >> 1); 
}
