//https://practice.geeksforgeeks.org/problems/intersection-of-two-arrays2404/1/
int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
    if(m<n){
        swap(a,b);
        swap(m,n);
    }    
    unordered_map<int,int> umap;
    for(int i=0;i<n;i++){
        if(umap.find(a[i])==umap.end())
                umap[a[i]]++;
    }
    int cnt=0;
    for(int j=0;j<m;j++){
            if(umap.find(b[j])!=umap.end() && umap[b[j]]!=0)
            {
                cnt++;
                umap[b[j]]--;
            }
    }
    return cnt;
    }
