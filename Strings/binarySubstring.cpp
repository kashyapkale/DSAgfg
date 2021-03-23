//https://practice.geeksforgeeks.org/problems/binary-string-1587115620/0
long binarySubstring(int n, string a){
        int cnt = 0;
        for(int i = 0;i<n;i++)
            if(a[i]=='1')
                cnt++;
        
        return ((cnt)*(cnt-1))/2;
        
    }
