//https://practice.geeksforgeeks.org/problems/inorder-successor-in-bst/1
Node * inOrderSuccessor(Node *root, Node *x){
    Node* parent = root;
    Node* temp = root;

    while (temp && temp != x) {

        if (temp->data < x->data) {
            temp = temp->right;
        }
        else{
            parent = temp;
            temp = temp->left;
        }
    }

    if (temp->right) {
        temp = temp->right;
        while (temp->left)
            temp = temp->left;
        return temp;
    }
    else
        return (x->data < parent->data)?parent:NULL;

}
