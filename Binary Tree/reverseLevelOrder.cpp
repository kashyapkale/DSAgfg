//https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1
vector<int> reverseLevelOrder(Node *node)
{
      queue<Node*> q;
      stack<int> stk;
      vector<int> ans;        
      if(!node)
        return ans;
        
      q.push(node);
      while(!q.empty()){
          if(q.front()->right)
                q.push(q.front()->right);
          if(q.front()->left)
                q.push(q.front()->left);
          ans.push_back(q.front()->data);
          q.pop();       
      }
      for(auto it:ans)
        stk.push(it);
      for(int i=0;i<ans.size();i++){
          //cout<<stk.top()<<endl;
          ans[i] = stk.top();
          stk.pop();
      }        
        return ans;
    }   
