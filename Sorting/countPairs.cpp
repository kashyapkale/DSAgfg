//https://practice.geeksforgeeks.org/problems/number-of-pairs-1587115620/0
long long countPairs(int X[], int Y[], int m, int n)
{

	sort(X, X + m);
	sort(Y, Y + n);
	long long yZero = 0, yOne = 0 , yTwo = 0;
	long long yTF = 0;

	for (long long i = 0; i < n; i++) {
		if (Y[i] == 0)
			yZero++;

		if (Y[i] == 1)
			yOne++;

		if (Y[i] == 2)
			yTwo++;

		if (Y[i] == 3 || Y[i] == 4)
			yTF++;
	}


	long long i = 0, j = 0;
	long long count = 0;

	while (i < m) {
		while ((Y[j] <= X[i]) && (j < n))
			j++;

		if (j == n)
			break;

		if (X[i] == 0 || X[i] == 1) {
			i++;
			continue;
		}

		count += (n - j);
		if (X[i] == 2 && Y[j] < 5)
			count -= yTF;

		if (X[i] == 3)
			count += yTwo;

		count += yZero;
		count += yOne;
		i++;
	}

	if (X[i] == 3)
		count += yTwo;


	long long r = m - i;
	count += (yOne * r);
	count += (yZero * r);

	return count;
}
/*The problem is to find numbers of pairs in array X and Y
where X[i]^Y[j] > Y[j]^X[i]

Test Cases :
Example 1:

Input:
M = 3, X[] = [2 1 6]
N = 2, Y[] = [1 5]
Output: 3
Explanation:
The pairs which follow xy > yx are
as such: 21 > 12,  25 > 52 and 61 > 16 .

Example 2:

Input:
M = 4, X[] = [2 3 4 5]
N = 3, Y[] = [1 2 3]
Output: 5
Explanation:
The pairs for the given input are
21 > 12 , 31 > 13 , 32 > 23 , 41 > 14 ,
51 > 15 .

Solution:
1)Sort both the arrays
2)After a few trial and error i came to know

if x<y:
	x^y > y^x with a few exceptions

exceptions
The above condition wont work with x=1 or x=0
The above condition wont work with x=2 if y=3
The above condition wont work with y=3 if x=2 //different than above point
The above condition wont work with x=2 if y=4

handling the above cases we will reach to our solution successfully
*/
