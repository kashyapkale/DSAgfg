//https://practice.geeksforgeeks.org/problems/possible-words-from-phone-digits-1587115620/1
void makeWord(string s, int arr[], int n, int level, unordered_map<int, vector<char>> &umap, vector<string> &v) {
	if (level == n - 1) {
		string temp = s;
		for (auto it : umap[arr[level]]) {
			s += it;
			v.push_back(s);
			s = temp;
		}
		return;
	}

	string temp = s;
	for (auto it : umap[arr[level]]) {
		s += it;
		makeWord(s, arr, n, level + 1, umap, v);
		s = temp;
	}
}


vector <string> possibleWords(int a[], int N)
{
	vector<string> v;
	unordered_map<int, vector<char>> umap;
	char ch = 'a';

	//Numbers to letter Dict
	for (int i = 2; i <= 9; i++) {
		int cnt = 3;
		while (cnt--) {
			umap[i].push_back(ch);
			ch++;
		}

		if (i == 7 || i == 9) {
			umap[i].push_back(ch);
			ch++;
		}

	}

	makeWord("", a, N, 0, umap, v);

	return v;
}
