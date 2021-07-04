//https://practice.geeksforgeeks.org/problems/next-permutation5226/1#
vector<int> nextPermutation(int N, vector<int> arr){
        int ind1=N-2,ind2=N-1;
        //int i=N-2;
        while(ind1>0 && arr[ind1]>arr[ind1+1]){
                ind1--;
        }
        
        
        while(ind2>0 && arr[ind1]>arr[ind2]){
                ind2--;
        }
        
        if(ind1==ind2){
            reverse(arr.begin(),arr.end());
            return arr;
        }
        
        swap(arr[ind1],arr[ind2]);
        reverse(arr.begin()+ind1+1,arr.end());
        return arr;
    }
