//https://practice.geeksforgeeks.org/problems/isomorphic-strings-1587115620/1
bool areIsomorphic(string str1, string str2)
    {
        if(str1.length()!=str2.length())
            return false;
        int alphabetsOne[256] = {0};
        int alphabetsTwo[256] = {0};
        for(int i=0;i<str1.length();i++){
                alphabetsOne[str1[i]]++;
                alphabetsTwo[str2[i]]++;
                if(alphabetsOne[str1[i]] != alphabetsTwo[str2[i]])
                    return false;
        }
            
        return true;
        
    }
