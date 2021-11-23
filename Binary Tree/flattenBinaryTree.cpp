//https://practice.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1
void flattenTreeUtil(Node* root, Node** prev){
    if (!root)
        return;

    flattenTreeUtil(root->right, prev);
    flattenTreeUtil(root->left, prev);

    root->right = *prev;
    root->left = NULL;
    *prev = root;
}

void flatten(Node *root){
    Node* prev = NULL;

    flattenTreeUtil(root, &prev);
}
