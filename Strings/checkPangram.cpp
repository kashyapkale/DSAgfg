//https://practice.geeksforgeeks.org/problems/pangram-checking-1587115620/0/
bool checkPangram (string &str) {
        vector<int> alphabets(26,1);
        //vector<int> alphabetsSmall(26,1);
        for(int i=0;i<str.length();i++)
        {
            if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')){
                    char diff = (str[i]>='a' && str[i]<='z')?'a':'A';
                    alphabets[str[i]-diff]--;
            }
        }
        
        for(auto it:alphabets){
            if(it>0)
                return false;
        }
        
        return true;
    }
