class Solution {
private:
Node* first;
Node* middle;
Node* last;
Node* prev;
void inOrder(Node* root){
    if (!root)
        return;

    inOrder(root->left);

    if (!prev)
        prev = root;
    else{
        if (prev->data > root->data) {
            if (!first) {
                first = prev;
                middle = root;
            }
            else
                last = root;
        }
    }
    prev = root;
    inOrder(root->right);
}

public:
void correctBST( struct Node* root ){
    if (!root)
        return;
    first = middle = last = prev = NULL;
    prev = new Node(INT_MIN);
    inOrder(root);
    if (first && last) swap(first->data, last->data);
    else if (first && middle) {
        swap(first->data, middle->data);
    }
}
