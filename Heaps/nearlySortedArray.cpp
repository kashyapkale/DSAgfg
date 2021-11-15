//https://practice.geeksforgeeks.org/problems/nearly-sorted-algorithm/0
//Nearly Sorted Array Sort Problem
void kSort(vector<int> &arr, int N, int K){
	int m = 0;
	priority_queue <int, vector<int>, greater<int> > minHeap;

	while (m < K) {
		minHeap.push(arr[m]);
		m++;
	}

	int i = 0;

	while (m < N) {
		minHeap.push(arr[m]);
		arr[i] = minHeap.top();
		minHeap.pop();
		m++;
		i++;
	}

	while (!minHeap.empty()) {
		arr[i] = minHeap.top();
		minHeap.pop();
		i++;
	}

}
