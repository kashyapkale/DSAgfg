//https://practice.geeksforgeeks.org/problems/stock-buy-and-sell-1587115621/1
vector<vector<int> > stockBuySell(vector<int> A, int n) {
	int minimum = A[0];
	int maximum = A[0];
	int profit = 0;
	int pArr[n];
	pArr[0] = 0;
	vector<vector<int>> ans;

	for (int i = 1; i < n; i++) {
		if (A[i] < minimum || A[i] < maximum) {
			minimum = maximum = A[i];
			pArr[i] = 0;
			continue;
		}

		maximum = A[i];
		pArr[i] = maximum - minimum;
	}

	/*for(int j =0;j<n;j++)
	    cout<<pArr[j]<<" ";

	cout<<endl;*/

	int k = 1;
	int startIndex = 0;
	int endIndex = 0;
	while (k < n) {
		if (pArr[k] == 0 && pArr[k - 1] != 0) {
			vector<int> p;
			p.push_back(startIndex);
			p.push_back(endIndex);
			startIndex = endIndex = k;
			ans.push_back(p);
			k++; continue;
		}

		if (pArr[k] == 0) {
			startIndex = endIndex = k;
			k++;
			continue;
		}

		endIndex = k;
		k++;

		if (k == n) {
			vector<int> p;
			p.push_back(startIndex);
			p.push_back(endIndex);
			ans.push_back(p);
		}
	}
	return ans;
}
