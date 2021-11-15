//https://practice.geeksforgeeks.org/problems/sum-of-elements-between-k1th-and-k2th-smallest-elements3133/1
int findKthSmallest(long long arr[], long long N, int K){
    long long m = 0;
    priority_queue<long long> maxHeap;

    while (m < K) {
        maxHeap.push(arr[m]);
        m++;
    }


    while (m < N) {
        maxHeap.push(arr[m]);
        maxHeap.pop();
        m++;
    }

    return maxHeap.top();
}

long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2){
    long long elem1 = findKthSmallest(A, N, K1);
    long long elem2 = findKthSmallest(A, N, K2);
    long long sum = 0;

    if (K1 > K2) {
        swap(K1, K2);
        swap(elem1, elem2);
    }
    for (long long i = 0; i < N; i++) {
        if (A[i] > elem1 && A[i] < elem2) {
            sum += A[i];
        }
    }

    return sum;
}
