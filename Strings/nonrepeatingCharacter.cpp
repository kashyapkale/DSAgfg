//https://practice.geeksforgeeks.org/problems/non-repeating-character-1587115620/0/
char nonrepeatingCharacter(string S)
    {
       unordered_map<char,int> umap;
       for(int i=0;i<S.length();i++)
           umap[S[i]]++;
       
       for(int i=0;i<S.length();i++)
           {
               if(umap[S[i]] == 1)
                    return S[i];
           }
       
       return '$';
    }
