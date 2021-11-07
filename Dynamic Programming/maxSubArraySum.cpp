//https://practice.geeksforgeeks.org/problems/kadanes-algorithm4325/1
int maxSubArray(vector<int> array) {
    int maximum = INT_MIN,sum = 0;
    for(int i=0;i<array.size();i++){
            sum += array[i];
            maximum = max(maximum,sum);
            if(sum<0)
                sum = 0;
    }
    return maximum;
}
