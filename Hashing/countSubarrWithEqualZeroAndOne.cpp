//https://practice.geeksforgeeks.org/problems/count-subarrays-with-equal-number-of-1s-and-0s-1587115620/0/
long long int countSubarrWithEqualZeroAndOne(int arr[], int N)
    {
        unordered_map<int, int>umap;

    umap[0] = 1;
    int sum = 0;
    long long maximum = 0;
    for (int i = 0; i < N; i++) {
        sum += (arr[i] == 1)?1:-1;
        if (umap.find(sum) != umap.end()) {
            maximum+=umap[sum];
        }
        
            umap[sum]++;
        
    }

    return maximum;
    }
