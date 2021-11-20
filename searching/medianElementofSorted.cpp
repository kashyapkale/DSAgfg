//https://practice.geeksforgeeks.org/problems/median-of-2-sorted-arrays-of-different-sizes/0
double MedianOfArrays(vector<int>& array1, vector<int>& array2){

    if (array2.size() < array1.size())
        return MedianOfArrays(array2, array1);

    int N1 = array1.size();
    int N2 = array2.size();


    int low = 0;
    int high = N1;

    while (low <= high) {
        int cut1 = (low + high) / 2;
        int cut2 = (N1 + N2 + 1) / 2 - cut1;

        double left1 = (cut1 == 0)?INT_MIN:array1[cut1 - 1];
        double left2 = (cut2 == 0)?INT_MIN:array2[cut2 - 1];

        double right1 = (cut1 == N1)?INT_MAX:array1[cut1];
        double right2 = (cut2 == N2)?INT_MAX:array2[cut2];

        if (left1 <= right2 && left2 <= right1) {
            if ((N1 + N2) % 2 == 0)
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            else{
                return double(max(left1, left2));
            }
        }
        else if (left1 > right2) {
            high = cut1 - 1;
        }
        else{
            low = cut1 + 1;
        }

    }
    return 0.0;
}
