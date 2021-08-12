//https://practice.geeksforgeeks.org/problems/decode-the-pattern1138/1
string lookandsay(int n) {
        string num = "1";

        if (n == 1)
                return "1";
        while (n >= 2) {
                char s = num[0];
                int cnt = 1;
                string ans = "";
                for (int i = 1; i < num.length(); i++) {
                        if (num[i - 1] != num[i]) {
                                ans += to_string(cnt) + s;
                                cnt = 1;
                                s = num[i];
                                continue;
                        }
                        cnt++;
                }
                ans += to_string(cnt) + s;
                //cout<<"------N : "<<n<<"-------"<<endl;
                //cout<<ans<<endl;
                num = ans;
                n--;
        }

        return num;
}
