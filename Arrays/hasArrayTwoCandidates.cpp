//https://practice.geeksforgeeks.org/problems/key-pair5616/1#
//pair to sum X , Done using hashing
bool hasArrayTwoCandidates(int arr[], int n, int x) {
	    unordered_map<int,int> umap;
	    for(int i=0;i<n;i++)
	        umap[arr[i]]++;
	   
	    for(int i=0;i<n;i++){
	        //cout<<"A  "<<arr[i]<<" : 1"<<"B  "<<abs(arr[i]-x)<<" : "<<umap[abs(arr[i]-x)]<<endl;
	        if(arr[i]<x && umap[abs(arr[i]-x)] )
	            if(abs(arr[i]-x)!=arr[i] || umap[abs(arr[i]-x)]>1)
	                return true;
	            
	    }
	   
	   return false;
	    
	}
