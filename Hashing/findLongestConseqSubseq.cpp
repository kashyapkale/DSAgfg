//https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/0
int findLongestConseqSubseq(int arr[], int n){
  set<int> hashSet;

  for (int i = 0; i < n; i++)
    hashSet.insert(arr[i]);
  int maximum = INT_MIN;

  for (int i = 0; i < n; i++) {
    if (!hashSet.count(arr[i] - 1)) {
      int k = arr[i];
      int cnt = 0;
      while (hashSet.count(k)) {
        cnt++;
        k++;
      }
      maximum = max(maximum, cnt);
    }
  }

  return maximum;

}
