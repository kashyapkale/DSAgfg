//GFG Easy? ;_;
//https://practice.geeksforgeeks.org/problems/maximum-gap3845/1

//Leetcode Hard -_-
//https://leetcode.com/problems/maximum-gap

//Solved using Pegion Hole Principle
int maxSortedAdjacentDiff(int* arr, int n) {
	//Step1 - Find MAX and Min elements
	if (n < 2)
		return 0;

	int maxElem = INT_MIN, minElem = INT_MAX;

	for (int i = 0; i < n; i++) {
		maxElem = max(maxElem, arr[i]);
		minElem = min(minElem, arr[i]);
	}

	//Step2 - Calculate Bucket Size
	int bucketSize = int(ceil((double)(maxElem - minElem) / (n - 1)));

	//Step3 - Make Bucket Start and Bucket End Arrays
	//Buckets Req = N-1
	int maxBucket[n - 1];
	int minBucket[n - 1];

	for (int i = 0; i < n - 1; i++) {
		maxBucket[i] = INT_MIN;
		minBucket[i] = INT_MAX;
	}
	//Step4 Enter Elements in buckets , Keep track of max element and min element in all the buckets
	for (int i = 0; i < n; i++) {
		if (arr[i] == maxElem || arr[i] == minElem)
			continue;
		int bucketIndex = (arr[i] - minElem) / bucketSize;
		maxBucket[bucketIndex] = max(maxBucket[bucketIndex], arr[i]);
		minBucket[bucketIndex] = min(minBucket[bucketIndex], arr[i]);
	}

	int maxGap = INT_MIN;

	//Step5 Calculating all the gaps
	for (int i = 0; i < n - 1; i++) {
		if (maxBucket[i] == INT_MIN)
			continue;

		int gap = minBucket[i] - minElem;
		maxGap = max(gap, maxGap);
		minElem = maxBucket[i];
	}
	maxGap = max(maxElem - minElem, maxGap);
	return maxGap;
}
