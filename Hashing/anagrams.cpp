//https://practice.geeksforgeeks.org/problems/print-anagrams-together/1#
vector<vector<string> > Anagrams(vector<string>& string_list)
{
  unordered_map<string, vector<int> > umap;
  int index = 0;
  vector<vector<string>> ans;

  for (auto s:string_list)
    {
      string temp = s;
      sort(temp.begin(), temp.end());
      umap[temp].push_back(index);
      index++;
    }

  for (auto i:umap)
    {
      vector<string> v;
      for (int ind = 0;ind<i.second.size();ind++)
        v.push_back(string_list[i.second[ind]]);
      ans.push_back(v);
    }

  return ans;
}
