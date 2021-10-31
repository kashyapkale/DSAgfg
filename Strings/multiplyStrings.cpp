//https://practice.geeksforgeeks.org/problems/multiply-two-strings/1/
string multiplyStrings(string s1, string s2) {


       if (s1 == "0" || s2 == "0")
              return "0";

       bool flag = ((s1[0] == '-' || s2[0] == '-') && !(s1[0] == '-' && s2[0] == '-'))?true:false;

       if (s1[0] == '-')
              s1 = s1.substr(1, s1.length() - 1);

       if (s2[0] == '-')
              s2 = s2.substr(1, s2.length() - 1);

       int n = s1.length();
       int m = s2.length();

       if (m > n) {
              swap(m, n);
              s1.swap(s2);
       }
       vector<int> ansArr(n + m, 0);
       int mulFactor = 0;

       int j = s2.length() - 1;


       while (j >= 0) {
              int carry = 0;
              int k = ansArr.size() - 1 - mulFactor;
              int i = s1.length() - 1;
              int jVal = (s2[j] - '0');
              while (i >= 0 || carry != 0) {
                     int iVal = (i >= 0)?(s1[i] - '0'):0;
                     int temp = jVal * iVal + carry + ansArr[k];
                     //cout<<temp<<endl;
                     ansArr[k] = (temp % 10);
                     carry = temp / 10;
                     //cout<<"Carry : "<<carry<<endl;
                     k--;
                     i--;
              }
              if (carry != 0)
                     ansArr[k] += carry;
              /*for(int l=0;l<ansArr.size();l++){
                    cout<<ansArr[l];
                 }*/
              //cout<<endl;

              mulFactor++;
              j--;
       }

       int t = 0;

       while (ansArr[t] == 0)
              t++;
       string ans = "";

       if (flag)
              ans += '-';
       while (t < m + n) {
              ans += to_string(ansArr[t]);
              t++;
       }
       return ans;
}
