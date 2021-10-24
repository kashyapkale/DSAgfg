//https://practice.geeksforgeeks.org/problems/case-specific-sorting-of-strings4845/0/
string caseSort(string str, int n){
    vector<int> capitalArr(26, 0);
    vector<int> smallArr(26, 0);
    string str2="";
    //str.copy(str2, sizeof str);

    for (int i = 0; i < n; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            capitalArr[str[i] - 'A']++;
        }
        if (str[i] >= 'a' && str[i] <= 'z') {
            smallArr[str[i] - 'a']++;
        }
    }

    int p = 0, q = 0;

    for (int i = 0; i < n; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            while (!capitalArr[p]) {
                p++;
            }
            //cout<<p<<endl;
            str2 += p+'A';
            capitalArr[p]--;
        }
        if (str[i] >= 'a' && str[i] <= 'z') {
            while (!smallArr[q]) {
                q++;
            }
            str2 += q+'a';
            smallArr[q]--;
        }
    }

    return str2;

}
