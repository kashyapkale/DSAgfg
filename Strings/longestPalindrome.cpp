//https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1
//Solution is in O(N^2) and O(1) Space
//Can Be Optimized by 2D Dynamic Programming

string longestPalin (string S) {
	int max_length = 1;
	int start = 0;
	//int i = 0, j = 0;
	for (int i = 0; i < S.length(); i++) {
		int low = i;
		int high = i;
		int size = S.length();
		int len = 0;
		while (S[low] == S[high] && low >= 0 && high < size) {
			len = high - low + 1;
			low--;
			high++;
		}
		if (len > max_length) {
			max_length = len;
			start = low + 1;
		}

	}

	for (int i = 0; i < S.length(); i++) {
		int low = i;
		int high = i + 1;
		int size = S.length();
		int len = 0;
		while (S[low] == S[high] && low >= 0 && high < size) {
			len = high - low + 1;
			low--;
			high++;
		}
		if (len > max_length) {
			max_length = len;
			start = low + 1;
		}

	}

	return S.substr(start, max_length);

}

//Solution 
//Need to check seprately for palindromic substrings with odd length and even length
//Start from 0th index and for every ith element consider ith element as middle of palindromic substring and traverse to its right and left until S[left] == S[right]
//once you get max length of palindromic substring considering ith element as middle element compare it with max length till now
//if greater update maxlength and start point
//return substring starting with index start and length max_length
