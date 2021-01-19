https://practice.geeksforgeeks.org/problems/count-total-digits-in-a-number/0
int countDigits(int n)
{
   if(n<10)
    return 1;
    
    return countDigits(n/10) + 1;
}
