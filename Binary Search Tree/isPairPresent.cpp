//https://practice.geeksforgeeks.org/problems/find-a-pair-with-given-target-in-bst/1
//(One of the best codes i enjoyed writing)
Node* getNextLeft(stack<Node*> &s)
{
  Node* temp = s.top();

  s.pop();
  if (temp->right)
    {
      s.push(temp->right);
      while (s.top()->left)
        {
          s.push(s.top()->left);
        }
    }
  return temp;
}

Node* getNextRight(stack<Node*> &s)
{
  Node* temp = s.top();

  s.pop();
  if (temp->left)
    {
      s.push(temp->left);
      while (s.top()->right)
        {
          s.push(s.top()->right);
        }
    }
  return temp;
}

int isPairPresent(struct Node *root, int target)
{
  stack<Node*> ls;
  stack<Node*> rs;

  if (!root || (!root->right && !root->left))
    return 0;
  //populate left stack
  ls.push(root);
  while (ls.top()->left)
    {
      ls.push(ls.top()->left);
    }

  //populate right stack
  rs.push(root);
  while (rs.top()->right)
    {
      rs.push(rs.top()->right);
    }

  //2 pointers logic
  Node* leftPtr = getNextLeft(ls);
  Node* rightPtr = getNextRight(rs);

  while (leftPtr->data < rightPtr->data)
    {
      int tempSum = leftPtr->data + rightPtr->data;
      if (tempSum == target)
        return 1;
      else if (tempSum > target)
        rightPtr = getNextRight(rs);
      else
        leftPtr = getNextLeft(ls);
    }

  return 0;
}
