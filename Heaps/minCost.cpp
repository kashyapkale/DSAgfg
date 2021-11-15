//https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/0
long long minCost(long long arr[], long long n) {
    priority_queue <long long, vector<long long>, greater<long long> > minHeap;

    for (long long i = 0; i < n; i++) {
        minHeap.push(arr[i]);
    }
    long long finalCost = 0;
    while (minHeap.size() >= 2) {
        long long cost = 0;
        cost += minHeap.top();
        minHeap.pop();
        cost += minHeap.top();
        minHeap.pop();
        finalCost += cost;
        minHeap.push(cost);
    }

    return finalCost;
}
