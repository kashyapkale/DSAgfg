//https://practice.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1

//Remember Can be done without using stack
//just use for loop and iterate from n-1 to 0 , simplest solution

//solution using array
vector<int> leaders(int a[], int n) {
	stack<int> s;
	for (int i = 0; i < n; i++) {
		if (s.empty()) {
			s.push(a[i]);
			continue;
		}

		while (!s.empty() && s.top() < a[i])
			s.pop();

		s.push(a[i]);
	}

	vector<int> ans;

	while (!s.empty()) {
		ans.push_back(s.top());
		s.pop();
	}

	reverse(ans.begin(), ans.end());

	return ans;
}
