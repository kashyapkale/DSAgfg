//https://practice.geeksforgeeks.org/problems/implement-atoi/1#
int atoi(string s) {
        int diff = 48,ans = 0,i = 0;
        bool flag = true;
        if(s[0] == '-'){
            i = 1;
            flag = false;
        }
  
        for (; i < s.length(); i++) {
                if (s[i] < 48 || s[i] > 57)
                        return -1;

                ans = (ans * 10) + (s[i] - 48);
        }
        
        if(!flag)
            return ans *= -1;
        
        return ans;
}
