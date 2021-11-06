//https://practice.geeksforgeeks.org/problems/max-length-chain/1
/*
   struct val{
    int first;
    int second;
   };*/
   
bool comp(val p1, val p2){
	return p1.second < p2.second;
}

//Util Function
int maxChainLenUtil(int i, int n, struct val p[], vector<val> &ansArr, vector<vector<int> > &dp){
	if (i == n) {
		return ansArr.size();
	}

	int n1 = ansArr.size();

	if (dp[i][n1] != -1) {
		return dp[i][n1];
	}


	if (ansArr.size() == 0) {
		int max1, max2;
		ansArr.push_back(p[i]);
		max1 = maxChainLenUtil(i + 1, n, p, ansArr, dp);
		ansArr.pop_back();
		max2 = maxChainLenUtil(i + 1, n, p, ansArr, dp);
		return dp[i][n1] = max(max1, max2);
	}
	int max1 = INT_MIN, max2 = INT_MIN;



	if (ansArr[n1 - 1].second < p[i].first) {
		ansArr.push_back(p[i]);
		max1 = maxChainLenUtil(i + 1, n, p, ansArr, dp);
		ansArr.pop_back();
	}

	max2 = maxChainLenUtil(i + 1, n, p, ansArr, dp);
	return dp[i][n1] = max(max1, max2);
}

//Main Logic Function
int maxChainLen(struct val p[], int n){
	vector<val> ansArr;
	sort(p, p + n, comp);
	vector<vector<int> > dp(n + 5, vector<int>(n + 5, -1));
	return maxChainLenUtil(0, n, p, ansArr, dp);
}
