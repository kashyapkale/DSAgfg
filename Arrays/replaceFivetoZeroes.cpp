//https://practice.geeksforgeeks.org/problems/replace-all-0s-with-5/1
int convertFive(int n) {
    int temp = n;
    int mul = 1;
    while(temp){
        int c = temp%10;
        if(c==0){
            n+=5*mul;
        }
        temp = temp/10;
        mul = mul * 10;
    }
    return n;
}
