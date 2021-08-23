//https://practice.geeksforgeeks.org/problems/separate-chaining-in-hashing-1587115621/0/?track=DSASP-Hashing&batchId=274#
vector<vector<int>> separateChaining(int hashSize,int arr[],int sizeOfArray)
    {
        vector<vector<int>> ans(hashSize);
       for(int i=0;i<sizeOfArray;i++)
            ans[arr[i]%hashSize].push_back(arr[i]);
       
       return ans;
    }
