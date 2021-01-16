//https://practice.geeksforgeeks.org/problems/swap-all-odd-and-even-bits-1587115621/0
unsigned int swapBits(unsigned int n)
{
	int oddMask = 0x55555555;
	int evenMask = 0xAAAAAAAA;
	
	int even = n&evenMask;
	int odd = oddMask&n;
	
	even>>=1;
	odd<<=1;
	
	return (even | odd);	
}
