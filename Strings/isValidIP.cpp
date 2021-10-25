//https://practice.geeksforgeeks.org/problems/validate-an-ip-address-1587115621/0
int isValid(string s) {
    int cnt = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '.') {
            cnt++;
        }
    }
    if (cnt != 3)
        return 0;

    cnt = 0;
    set<string> st;

    for (int i = 0; i < 256; i++) {
        st.insert(to_string(i));
    }

    string temp = "";

    for (int i = 0; i < s.length(); i++) {
        if (s[i] != '.')
            temp.push_back(s[i]);
        else if (s[i] == '.') {
            if (st.find(temp) == st.end())
                return 0;
            temp = "";
        }
    }

    if (st.find(temp) == st.end())
        return 0;

    return 1;

}
