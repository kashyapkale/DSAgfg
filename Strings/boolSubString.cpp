//https://practice.geeksforgeeks.org/problems/distinct-pattern-search-1587115620/1
bool search(string pat, string txt) 
    { 
    	//unordered_map<char,int> umap;
        for(int i = 0;i<txt.length();i++){
            if(pat[0]==txt[i]){
                string s = txt.substr(i,pat.length());
                if(pat==s)
                    return true;
            }
        }
        return false;
    	
    }
