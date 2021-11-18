//https://practice.geeksforgeeks.org/problems/get-minimum-element-from-stack/1/
class Solution{
    int minEle;
    stack<int> s;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           if(s.empty())
                return -1;
           return minEle;
       }
       
       /*returns poped element from stack*/
       int pop(){
            if(s.empty()){
                return -1;
            }
            else{
                int temp;
                if(s.top()>=minEle){
                temp = s.top();
                s.pop();
            }
           else{
               temp = minEle;
               minEle = (2*minEle)-s.top();
               s.pop();
           }
           return temp;
            }
       }
       
       /*push element x into the stack*/
       void push(int x){
           if(s.empty()){
               s.push(x);
               minEle = x;
           }
           else{
               if(x>=minEle)
                    s.push(x);
                else{
                    int temp = (2*x)-minEle;
                    minEle = x;
                    s.push(temp);
                }
           }
           
       }
};
