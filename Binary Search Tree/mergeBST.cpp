//https://practice.geeksforgeeks.org/problems/merge-two-bst-s/0/
void incPointer(stack<Node*> &s){
   Node* curr = s.top();

   s.pop();

   if (curr->right) {
      curr = curr->right;
      s.push(curr);
      while (curr->left) {
         s.push(curr->left);
         curr = curr->left;
      }
   }

}


vector<int> merge(Node *root1, Node *root2){
   vector<int> ans;
   stack<Node*> s1;
   stack<Node*> s2;

   s1.push(root1);
   s2.push(root2);
   Node* temp1 = root1;
   Node* temp2 = root2;

   while (temp1->left) {
      s1.push(temp1->left);
      temp1 = temp1->left;
   }
   while (temp2->left) {
      s2.push(temp2->left);
      temp2 = temp2->left;
   }

   while (!s1.empty() && !s2.empty()) {
      if (s1.top()->data == s2.top()->data) {
         ans.push_back(s1.top()->data);
         ans.push_back(s2.top()->data);
         incPointer(s1);
         incPointer(s2);
      }
      else if (s1.top()->data < s2.top()->data) {
         ans.push_back(s1.top()->data);
         incPointer(s1);
      }
      else{
         ans.push_back(s2.top()->data);
         incPointer(s2);
      }
   }

   while (!s1.empty()) {
      ans.push_back(s1.top()->data);
      incPointer(s1);
   }
   while (!s2.empty()) {
      ans.push_back(s2.top()->data);
      incPointer(s2);
   }

   return ans;
}
