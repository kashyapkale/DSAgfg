//https://practice.geeksforgeeks.org/problems/preorder-traversal-and-bst4006/1
int canRepresentBST(int arr[], int N) {
        int root = INT_MIN;
        stack<int> s;
        
        for(int i=0;i<N;i++){
            while(!s.empty() && arr[i]>s.top()){
                root = s.top();
                s.pop();
            }
            if(root>arr[i])
                return 0;
            s.push(arr[i]);
        }
        
        return 1;
    }
