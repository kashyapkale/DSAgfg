//https://practice.geeksforgeeks.org/problems/generate-ip-addresses/1

bool isIPValid(int i, int j, int k, int n, string &s, set<string> &checkIP){
        string s1 = s.substr(0, i + 1);
        string s2 = s.substr(i + 1, j - i);
        string s3 = s.substr(j + 1, k - j);
        string s4 = s.substr(k + 1, (n - 1) - k);

        if (checkIP.find(s1) == checkIP.end())
                return false;
        if (checkIP.find(s2) == checkIP.end())
                return false;
        if (checkIP.find(s3) == checkIP.end())
                return false;
        if (checkIP.find(s4) == checkIP.end())
                return false;

        return true;
}


vector<string> genIp(string &s) {
        vector<string> ans;
        set<string> st;
        int n = s.length();
        for (int i = 0; i < 256; i++) {
                st.insert(to_string(i));
        }

        for (int i = 0; i < n - 3; i++) {
                for (int j = i + 1; j < n - 2; j++) {
                        for (int k = j + 1; k < n - 1; k++) {
                                if (isIPValid(i, j, k, n, s, st)) {
                                        string temp = s.substr(0, i + 1) + "." + s.substr(i + 1, j - i) + "." + s.substr(j + 1, k - j) + "." + s.substr(k + 1, (n - 1) - k);
                                        ans.push_back(temp);
                                }
                        }
                }
        }

        return ans;
}
