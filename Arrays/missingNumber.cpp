//Missing Number
//https://practice.geeksforgeeks.org/problems/smallest-positive-missing-number-1587115621/1
int missingNumber(int arr[], int n) {
    int containsOne = 0;
    
    if(n==0)
        return 1;
    
	for (int i = 0; i < n; i++) {
	    
	    if(arr[i]==1)
	        containsOne = 1;
	   
		if (arr[i] < 1 || arr[i] > n)
			arr[i] = 1;
	}
	
	if(containsOne==0)
        return 1;
    
	for (int i = 0; i < n; i++) {
		if (arr[abs(arr[i]) - 1] > 0)
			arr[abs(arr[i]) - 1] *= -1;
	}

    
	for (int i = 0; i < n; i++) {
		if (arr[i] > 0)
			return i + 1;
	}

	return n + 1;
}
