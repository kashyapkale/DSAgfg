//https://practice.geeksforgeeks.org/problems/remove-duplicate-elements-from-sorted-array/1
int remove_duplicate(int a[], int n){
        int i = 0;
        int j = 1;

        while (j < n) {
                if (a[i] != a[j]) {
                        i++;
                        swap(a[i], a[j]);
                }
                j++;
        }
        return i + 1;
}
