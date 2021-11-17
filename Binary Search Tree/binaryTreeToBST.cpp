//https://practice.geeksforgeeks.org/problems/binary-tree-to-bst/1/
void retriveData(Node* root, vector<int> &inOrder){
    if (!root)
        return;

    retriveData(root->left, inOrder);
    inOrder.push_back(root->data);
    retriveData(root->right, inOrder);
}

void modifyTree(Node* root, vector<int> &inOrder, int &i){
    if (!root)
        return;

    modifyTree(root->left, inOrder, i);
    root->data = inOrder[i];
    i++;
    modifyTree(root->right, inOrder, i);
}

Node *binaryTreeToBST(Node *root){
    vector<int> inOrder;

    retriveData(root, inOrder);
    sort(inOrder.begin(), inOrder.end());
    int i = 0;

    modifyTree(root, inOrder, i);
    return root;
}
