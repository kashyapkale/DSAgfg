//https://practice.geeksforgeeks.org/problems/print-common-nodes-in-bst/1/
//Find Common Nodes in Two BSTs
void inorderTraversal(Node* root, unordered_set<int> &s1, vector<int> &ans, bool flag){
    if (!root)
        return;

    inorderTraversal(root->left, s1, ans, flag);

    if (!flag)
        s1.insert(root->data);
    else{
        if (s1.find(root->data) != s1.end())
            ans.push_back(root->data);
    }

    inorderTraversal(root->right, s1, ans, flag);
}



vector <int> findCommon(Node *root1, Node *root2){
    vector<int> ans;
    unordered_set<int> s;

    inorderTraversal(root1, s, ans, false);
    inorderTraversal(root2, s, ans, true);

    return ans;
}
