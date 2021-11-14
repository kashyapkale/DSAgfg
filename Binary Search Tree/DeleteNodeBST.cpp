//https://practice.geeksforgeeks.org/problems/delete-a-node-from-bst/0
//Delete a Node from BST
Node* helper(Node* root){
    if (!root->right && !root->left)
        return NULL;
    if (!root->right)
        return root->left;
    if (!root->left)
        return root->right;
    Node* temp = root;

    temp = temp->left;
    while (temp->right) {
        temp = temp->right;
    }
    temp->right = root->right;
    return root->left;
}



Node *deleteNode(Node *root, int X) {
    if (!root)
        return NULL;

    if (root->data == X)
        return helper(root);

    Node *temp = root;

    while (temp) {

        if (temp->data < X) {
            if (temp->right && temp->right->data == X) {
                temp->right = helper(temp->right);
                break;
            }
            else
                temp = temp->right;
        }
        else{
            if (temp->left && temp->left->data == X) {
                temp->left = helper(temp->left);
                break;
            }
            else
                temp = temp->left;
        }
    }

    return root;

}
