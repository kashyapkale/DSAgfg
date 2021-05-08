//https://practice.geeksforgeeks.org/problems/counting-sort/0
string countSort(string arr) {
	int alphabets[26] = {0};
	for (int i = 0; i < arr.length(); i++)
		alphabets[arr[i] - 97]++;
	string s = "";
	for (int i = 0; i < 26; i++)
		if (alphabets[i]) {
			int temp = alphabets[i];
			while (temp--)
				s += i + 97;
		}
	return s;
}
