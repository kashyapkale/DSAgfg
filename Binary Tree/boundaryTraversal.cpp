//https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

//left boundary
void leftBoundary(vector<int> &ans, Node* root)
{
  if (!root)
    return;
  Node* temp = root;

  while (temp)
    {
      if (temp->right || temp->left)
        ans.push_back(temp->data);
      if (temp->left)
        temp = temp->left;
      else
        temp = temp->right;
    }
}


//right boundary
void rightBoundary(vector<int> &ans, Node* root)
{
  if (!root)
    return;
  Node* temp = root;

  while (temp)
    {
      if (temp->right || temp->left)
        ans.push_back(temp->data);
      if (temp->right)
        temp = temp->right;
      else
        temp = temp->left;
    }
}


//void leaf nodes
void leafNodes(vector<int> &ans, Node* root)
{
  if (!root)
    return;
  if (!root->left && !root->right)
    {
      ans.push_back(root->data);
      return;
    }

  leafNodes(ans, root->left);
  leafNodes(ans, root->right);
}

vector <int> printBoundary(Node *root)
{
  vector<int> ans;

  if (!root)
    return ans;
  ans.push_back(root->data);
  //left boundary
  if (root->left)
    leftBoundary(ans, root->left);
  //leaf node
  leafNodes(ans, root);
  //right boundary
  if (root->right)
    {
      vector<int> temp;
      rightBoundary(temp, root->right);
      for (int i = temp.size() - 1; i >= 0; i--)
        ans.push_back(temp[i]);
    }
}






