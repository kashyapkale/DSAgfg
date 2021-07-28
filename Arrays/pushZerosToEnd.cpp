//https://practice.geeksforgeeks.org/problems/move-all-zeroes-to-end-of-array0751/1
void pushZerosToEnd(int arr[], int n) {
	    int i=0,j=0;
	    while(i<n){
	    	if(arr[i]!=0 && arr[j]!=0){
	    		i++;
	    		j++;
	    		continue;
	    	}
	    	if(arr[i]!=0 && arr[j]==0){
	    		swap(arr[i],arr[j]);
	    		j++;
	    	}
	    	i++;
	    }
	}
