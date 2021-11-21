//https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1
int median(vector<vector<int> > &matrix, int r, int c){
    int high = 2000;
    int low = 0;
    int n = r * c;
    int mid;

    while (low <= high) {
        mid = (high + low) / 2;
        int val = 0;
        for (int i = 0; i < r; i++) {
            int h = c - 1;
            int l = 0;

            while (l <= h) {
                int m = l + (h - l) / 2;
                if (matrix[i][m] <= mid) l = m + 1;
                else h = m - 1;
            }
            val += l;
        }
        if (n / 2 >= val) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}
