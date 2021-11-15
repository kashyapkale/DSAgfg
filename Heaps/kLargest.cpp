//https://practice.geeksforgeeks.org/problems/k-largest-elements3736/1
vector<int> kLargest(int arr[], int n, int k){
	priority_queue <int> pq;

	for (int i = 0; i < n; i++) {
		pq.push(arr[i]);
	}
	vector<int> ans;

	while (k--) {
		ans.push_back(pq.top());
		pq.pop();
	}

	return ans;
}
