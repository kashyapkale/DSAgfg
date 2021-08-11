//https://practice.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1
class Solution
{
public:
priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int> > minHeap;
//Function to insert heap.
void insertHeap(int &x){

    if (maxHeap.size() == 0) {
        maxHeap.push(x);
        return;
    }

    if (x < maxHeap.top())
        maxHeap.push(x);
    else
        minHeap.push(x);
}

//Function to balance heaps.
void balanceHeaps(){
    if (maxHeap.size() > minHeap.size() + 1) {
        minHeap.push(maxHeap.top());
        maxHeap.pop();
    }

    else if (maxHeap.size() + 1 < minHeap.size()) {
        maxHeap.push(minHeap.top());
        minHeap.pop();
    }

    return;
}

//Function to return Median.
double getMedian(){
    double ans;

    balanceHeaps();
    int len1 = maxHeap.size();
    int len2 = minHeap.size();

    if (len1 == len2)
        return ans = (minHeap.top() + maxHeap.top()) / 2;
    if (len1 < len2)
        return minHeap.top();

    return maxHeap.top();

}
};
