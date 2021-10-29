//https://practice.geeksforgeeks.org/problems/needle-in-a-haystack/0
int NeedleinHaystack(string haystack, string needle) 
{
    int j=0;
    if(needle.length()==0)
        return 0;
    for(int i=0;i<haystack.length();i++){
        if(haystack[i] == needle[j]){
                bool flag = true;
                int k = i;
                while(j<needle.length() && k<haystack.length()){
                    if(haystack[k]!=needle[j])
                        {flag = false;
                            break;
                        }
                    j++;
                    k++;
                }
                if(flag)
                    return i;
                j=0;    
        }    
    }
    return -1;
}
