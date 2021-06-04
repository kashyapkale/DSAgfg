//https://practice.geeksforgeeks.org/problems/closer-to-sort-1587115620/1
int getTarget(int arr[], int m, int N) {
    bool notEdge = ((m + 1 != N) && (m - 1 != 0));

    if (notEdge) {
        if (arr[m] > arr[m + 1])
            return m + 1;

        if (arr[m] < arr[m - 1])
            return m - 1;

        return m;
    }


    if (m + 1 == N && (arr[m] < arr[m - 1]))
        return m - 1;

    if (m - 1 == 0 && (arr[m] > arr[m + 1]))
        return m + 1;

    return m;

}


int binarySearch(int arr[], int l, int r, int x, int N)
{
    while (l <= r) {
        int m = l + (r - l) / 2;

        int index = getTarget(arr, m, N);
        int target = arr[index];

        // Check if x is present at mid
        if (target == x)
            return index;

        // If x greater, ignore left half
        if (target < x)
            l = m + 1;

        // If x is smaller, ignore right half
        else
            r = m - 1;
    }

    // if we reach here, then element was
    // not present
    return -1;
}

int closer(int arr[], int N, int x) {

    return binarySearch(arr, 0, N - 1, x, N);

}

//Easy problem
/*Question
Given an array arr[](0-based indexing) of N integers which is closer sorted (defined below) and an element x. The task is to find the index of element x if it is present. If not present, then print -1.
Closer Sorted: The first array is sorted, but after sorting some elements are moved to either of the adjacent positions, i.e, maybe to the arr[i+1] or arr[i-1].

Example :
Input: N = 5, A[] = [3 2 10 4 40], x = 2
Output: 1
Explanation: 2 is present at index 1
(0-based indexing) in the given array.*/

/*Solution
1) Just figure out what is the correct element on that particular place
2)Use Binary Search*/
