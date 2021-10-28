//https://practice.geeksforgeeks.org/problems/run-length-encoding/0/
string encode(string src){
  string ans = "";
  string temp = "";
  //temp+=ans[0];
  int cnt = 1;
  int i;

  for (i = 1; i < src.length(); i++) {
    if (src[i] != src[i - 1]) {
      ans += src[i - 1];
      ans += to_string(cnt);
      cnt = 0;
    }
    cnt++;
  }
  ans += src[i - 1];
  ans += to_string(cnt);

  return ans;
}
