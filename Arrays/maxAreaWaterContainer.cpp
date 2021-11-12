//https://practice.geeksforgeeks.org/problems/container-with-most-water0535/1
long long maxArea(long long A[], int len){
    int i = 0, j = len - 1;
    int area = 0;

    while (i < j) {
        int height = min(A[i], A[j]);
        area = max(area, ((j - i) * height));
        if (A[i] < A[j]) {
            i++;
        }
        else{
            j--;
        }
    }
    return area;
}
