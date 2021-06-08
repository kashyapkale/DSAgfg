//https://practice.geeksforgeeks.org/problems/level-order-traversal/1#
vector<int> levelOrder(Node* node)
    {
      queue<Node*> q;    
      vector<int> ans;        
      if(!node)
        return ans;
        
      q.push(node);
      while(!q.empty()){
          if(q.front()->left)
                q.push(q.front()->left);
          if(q.front()->right)
                q.push(q.front()->right);
          ans.push_back(q.front()->data);
          q.pop();       
      }
            
        return ans;
    }
