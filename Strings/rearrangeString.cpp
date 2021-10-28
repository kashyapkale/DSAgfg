//https://practice.geeksforgeeks.org/problems/rearrange-characters4649/1
string rearrangeString(string str){
   unordered_map<char, int> umap;

   int n = str.length();

   for (int i = 0; i < str.length(); i++) {
      umap[str[i]]++;
   }

   priority_queue<pair<int, char> > pq;

   for (char ch = 'a'; ch <= 'z'; ch++) {
      if (umap[ch] > 0) {
         pq.push(make_pair(umap[ch], ch));
         if (umap[ch] > ((n + 1) / 2))
            return "-1";
      }
   }

   string ans = "";

   while (pq.size() >= 2) {
      char ch1 = pq.top().second;
      int cnt1 = pq.top().first;
      pq.pop();

      char ch2 = pq.top().second;
      int cnt2 = pq.top().first;
      pq.pop();
      ans += ch1;
      ans += ch2;

      if (cnt1 - 1 > 0)
         pq.push(make_pair(cnt1 - 1, ch1));

      if (cnt2 - 1 > 0)
         pq.push(make_pair(cnt2 - 1, ch2));

   }

   while (!pq.empty()) {
      ans += pq.top().second;
      pq.pop();
   }
   //cout<<ans<<endl;
   return ans;

}
