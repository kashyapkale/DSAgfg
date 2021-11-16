//https://practice.geeksforgeeks.org/problems/top-k-frequent-elements-in-array/1/
typedef pair<int, int> nPair;

vector<int> topK(vector<int>& nums, int k) {
        unordered_map<int, int> umap;

        for (int i = 0; i < nums.size(); i++) {
                umap[nums[i]]++;
        }

        priority_queue<nPair> maxHeap;

        for (auto it:umap) {
                maxHeap.push(make_pair(it.second, it.first));
        }

        vector<int> ans;

        while (k--) {
                ans.push_back(maxHeap.top().second);
                maxHeap.pop();
        }

        return ans;
}
