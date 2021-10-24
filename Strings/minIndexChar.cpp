//https://practice.geeksforgeeks.org/problems/minimum-indexed-character-1587115620/0
int minIndexChar(string str, string patt)
    {
        set<char> s;
        for(int i=0;i<patt.length();i++)
            s.insert(patt[i]);
        
        for(int i=0;i<str.length();i++){
            if(s.find(str[i])!=s.end())
                return i;
        }
        
        return -1;
        
    }
