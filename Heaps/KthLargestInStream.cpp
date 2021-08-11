//https://practice.geeksforgeeks.org/problems/kth-largest-element-in-a-stream2220/1
vector<int> kthLargest(int k, int arr[], int n){
        vector<int> ans;
        priority_queue<int, vector<int>, greater<int> > minHeap;
        int i;

        for (i = 0; i < k - 1; i++) {
                minHeap.push(arr[i]);
                ans.push_back(-1);
        }
        minHeap.push(arr[i]);
        ans.push_back(minHeap.top());
        i++;
        while (i < n) {
                if (minHeap.top() < arr[i]) {
                        minHeap.pop();
                        minHeap.push(arr[i]);
                        ans.push_back(minHeap.top());
                }
                else
                        ans.push_back(minHeap.top());

                i++;
        }

        return ans;

}
