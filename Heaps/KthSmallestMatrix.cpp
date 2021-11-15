//https://practice.geeksforgeeks.org/problems/kth-element-in-matrix/0
typedef pair<int, pair<int, int> > mPair;

int kthSmallest(int arr[MAX][MAX], int n, int k){
  int rows = n;
  //cout<<rows<<" are Rows"<<endl;
  int columns = n;
  //cout<<columns<<" are Columns"<<endl;

  priority_queue <mPair, vector<mPair>, greater<mPair> > minHeap;
  int j = 0;

  int limit = min(k, rows);

  for (int i = 0; i < limit; i++) {
    minHeap.push(make_pair(arr[i][j], make_pair(i, j)));
  }

  int ans = INT_MIN;
  vector<int> ansArr;

  while (ansArr.size() < k) {
    mPair temp = minHeap.top();
    minHeap.pop();
    ansArr.push_back(temp.first);
    temp.second.second++;
    if (temp.second.second < columns) {
      int x = temp.second.first;
      int y = temp.second.second;
      minHeap.push(make_pair(arr[x][y], make_pair(x, y)));
    }
  }
  //cout<<ansArr.size()<<endl;
  return ansArr[k - 1];

}
