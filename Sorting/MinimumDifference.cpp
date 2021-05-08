//https://practice.geeksforgeeks.org/problems/minimum-difference-in-an-array/0
int MinimumDifference(int arr[], int n)
    {
        sort(arr,arr+n);
        int minimum = INT_MAX;
        for(int i = 1;i<n;i++)
            minimum = min(minimum,arr[i]-arr[i-1]);
            
        return minimum;
        
    }
