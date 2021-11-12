//https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string-1587115620/1
void permutationUtil(string &S,vector<string> &ans,int index){
        int N = S.length();
        if(N==index+1){
            ans.push_back(S);
            return;
        }
        
        for(int i=index;i<N;i++){
                swap(S[i],S[index]);
                permutationUtil(S,ans,index+1);
                swap(S[i],S[index]);
        }   
    }
    
    
    vector<string> permutation(string S)
    {
        vector<string> ans;
        permutationUtil(S,ans,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
