//https://practice.geeksforgeeks.org/problems/excel-sheet-part-21138/0
int ExcelColumnNumber(string s)
    {
        int ans = 0;
        for(auto c:s){
                ans *= 26;
                ans+=c-'A'+1;
        }
        return ans;
    }
