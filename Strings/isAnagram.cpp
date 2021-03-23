//https://practice.geeksforgeeks.org/problems/anagram-1587115620/0
bool isAnagram(string a, string b) {


	int sizeOfA = a.length();
	int sizeOfB = b.length();

	if (sizeOfA != sizeOfB)
		return false;

	unordered_map<char, int> umap;

	for (int i = 0; i < sizeOfA; i++)
		umap[a[i]]++;


	for (int i = 0; i < sizeOfB; i++)
		umap[b[i]]--;

	for (auto it : umap) {
		if (it.second > 0)
			return false;
	}

	return true;

}
