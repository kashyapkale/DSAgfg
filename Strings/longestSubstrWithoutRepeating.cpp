//https://practice.geeksforgeeks.org/problems/longest-substring-without-repeating-characters/1
int SubsequenceLength(string s){
	vector<int> umap(256, -1);
	int right = 0;
	int left = 0;
	int n = s.length();
	int maximum = 0;

	while (right < n) {
		if (umap[s[right]] != -1)
			 left = max(umap[s[right]] + 1, left);
		umap[s[right]] = right;
		maximum = max(maximum,right-left+1);	
		right++;
	}
	return maximum;
}
