//https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1#
vector<int> diagonal(Node *root)
{
   vector<int> ans;

	if (!root)
		return ans;
    queue<Node*> q;
    q.push(root);
	while(!q.empty()){
	        Node* temp = q.front();
	        while(temp){
	            ans.push_back(temp->data);
	            if(temp->left)
	                q.push(temp->left);
	            temp = temp->right;
	        }
	        q.pop();
	}
	return ans;
}
