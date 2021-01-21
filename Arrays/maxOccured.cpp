//https://practice.geeksforgeeks.org/problems/maximum-occured-integer4602/0

//BruteForce Approach
int maxOccured(int L[], int R[], int n, int maxx) {
	int freq[maxx + 1] = {0};
	for (int i = 0; i < n; i++) {
		for(int j=L[i];j<=R[i];j++){
			freq[j]++;
		}
	}
	int ans,maxiumum = INT_MIN;
	for(int i=1;i<maxx+1;i++){
		if(freq[i]>maximum){
			maximum = freq[i];
			ans = i;
		}
	}
	return ans;
}

//Optimized Approach
int maxOccured(int L[], int R[], int n, int maxx) {
	int freq[maxx + 1] = {0};
	for (int i = 0; i < n; i++) {
		freq[L[i]]++;
		freq[R[i] + 1]--;
	}
	int ans, maximum = INT_MIN;
	for (int i = 1; i < maxx + 1; i++) {
		freq[i] += freq[i-1];
		//cout<<"Freq "<<freq[i]<<endl;
		if (freq[i] > maximum) {
			maximum = freq[i];
			ans = i;
		}
	}
	return ans;
}
